#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "removepkg.h"

int removepkg(int argc, char **argv) {
  if (argc <= 0) {
    help();
    return 1;
  }

  else {
    char *cmd = strdup("removepkg"); /* this needs to be freed, and we cant
					 free string literals. */

    for (int i = 0; i < argc; i++) {
      char *tmp;
      asprintf(&tmp, "%s %s", cmd, argv[i]);
      free(cmd);
      cmd = tmp;
    }

    FILE *fp = popen(cmd, "r");
    free(cmd);
    if (!fp) {
      fprintf(stderr, "Failed to open a shell!");
      return 1;
    }

    int c; // fgetc returns int, EOF is -1
    while ((c = fgetc(fp)) != EOF) { putchar(c); } // prints fp int by int
    pclose(fp);
    return 0;
  }
}
