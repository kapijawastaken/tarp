#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "commands/help.h" // dont move this one.
#include "commands/removepkg.h"
#include "commands/list.h"
#include "commands/count.h"

int main(int argc, char **argv) {
  if (argc <= 1) {
    printf("%s", help());
    return 1;
  }
  else if (strcmp(argv[1], "h") == 0 || strcmp(argv[1], "help") == 0) {
    printf("%s", help());
  }
  else if (strcmp(argv[1], "r") == 0 || strcmp(argv[1], "remove") == 0) {
    char *bye = removepkg(argc - 2, argv + 2);
    printf("%s", bye);
    free(bye);
  }
  else if (strcmp(argv[1], "c") == 0 || strcmp(argv[1], "count") == 0) {
    printf("%d\n", count());
  }
  else if (strcmp(argv[1], "l") == 0 || strcmp(argv[1], "list") == 0) {
    char **pkgs = list();

    for (int i = 0; pkgs[i] != NULL; i++) {
      printf("%s\n", pkgs[i]);
      free(pkgs[i]);
    }

    free(pkgs);
  }
  else {
    printf("%s", help());
    return 1;
  }

  return 0;
}
