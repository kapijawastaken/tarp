#include "search.h"

#include <stdio.h>
#include <string.h>

#include <unistd.h>

#include "fnv1a.h"
#include "help.h"
#include "mirrors.h"

int search(char **search_arg) {
  if (search_arg[0] == nullptr) { help(); return 1; }
  char *entered = strdup(search_arg[0]);
  char **mlist = mirrors(TZ);
  char *checksum_path = nullptr; // we'll read through this
  char repoid[9];
  char buffer[256];
  
  if (mlist == nullptr) {
    fprintf(stderr, "%s\n",
	    "You don't have any mirrors set!\n"
	    "Go and do that by uncommenting one "
	    "or more mirrors in /etc/tarp/mirrors.");
    return 1;
  }
  
  for (int i = 0; mlist[i] != nullptr; i++) {
    mlist[i][strcspn(mlist[i], "\n")] = '\0';
    snprintf(repoid, 9, "%08x", fnv1a(mlist[i]));
    asprintf(&checksum_path, "/tmp/tarp/%s/CHECKSUMS.md5", repoid);

    if (access(checksum_path, W_OK) == -1) {
      fprintf(stderr, "Cannot access checksum of repo %s!\n"
	      "Please run tarp update.\n", repoid);
      return 1;
    }
    FILE *checksum_file = fopen(checksum_path, "r");
    if (!checksum_file) {
      fprintf(stderr, "%s not found!", checksum_path);
      return 1;
    }
    while (fgets(buffer, sizeof(buffer), checksum_file) != NULL) {
      if (strlen(buffer) <= 37) { continue; }
      char *line = buffer + 36;
      // 35 are taken up by the md5sum + 2 for ./

      line[strcspn(line, "\n")] = '\0'; // remove trailing newline
      size_t len = strlen(line);
      if (len < 4 || strcmp(line + len - 4, ".txz") != 0) { continue; }
      if (strstr(line, entered) != NULL) {
        printf("%s\n", line);
      }
    }
    fclose(checksum_file);
  }
  return 0;
}
