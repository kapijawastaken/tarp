#include <stdio.h>
#include <string.h>
#include "commands/help.h"

int main(int argc, char **argv) {
  if (argc <= 1) {
    printf("%s", help());
    return 1;
  }
  else if (strcmp(argv[1], "h") == 0 || strcmp(argv[1], "help") == 0) {
    printf("%s", help());
  }
  else {
    printf("%s", help());
    return 1;
  }

  /*
    char **names = list();
    for (int i = 0; names[i] != NULL; i++) {
    printf("%s\n", names[i]);
    free(names[i]);
    }
    free(names);
  */
  return 0;
}
