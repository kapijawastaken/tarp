#include <stdio.h>
#include <string.h>
#include "commands/help.h"

int main(char **args) {
  if (sizeof(args) / sizeof(*args) <= 1) {
    printf(help());
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
