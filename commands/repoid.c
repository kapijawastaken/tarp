#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "mirrors.h"
#include "fnv1a.h"
#include "repoid.h"

int repoid(char **input) {
  if (input[0] == nullptr) {
    help();
    return 1;
   }
  char *entered = strdup(input[0]);
  char **mlist = mirrors(tz);
  if (mlist == nullptr) {
    fprintf(stderr, "No repos available!\n");
    free(entered);
    return 1;
  }
  for (int i = 0; mlist[i] != nullptr; i++) {
    char tmp[9];
    snprintf(tmp, 9, "%08x", fnv1a(mlist[i]));
    if (strcmp(entered, tmp) == 0) {
      free(entered);
      printf("%s", mlist[i]);
      return 0;
    }
  }
  free(entered);
  fprintf(stderr, "Entered RepoID doesn't match any repos!\n");
  return 1;
}
