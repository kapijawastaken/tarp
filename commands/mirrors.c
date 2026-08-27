#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mirrors.h"

#define APPEND \
  tmp = realloc(mlist, sizeof(char*) * (count + 2)); \
  if (tmp == nullptr) { \
    fclose(fp); free(line); \
    if (mlist != nullptr) { mlist[count] = nullptr; } \
    return mlist; \
  } \
  mlist = tmp; \
  mlist[count++] = strdup(line);
/* were using #define here because goto causes problems
   and im too lazy to write a function */

char **mirrors(enum PKG type) {
  FILE *fp = fopen("/etc/tarp/mirrors", "r");
  if (!fp) {
    fprintf(stderr, "/etc/tarp/mirrors not found!");
    return nullptr;
  }
  char *line = nullptr;
  char **mlist = nullptr, **tmp = nullptr;
  size_t limit = 0; // getline() allocates this for us
  int count = 0;
  while (getline(&line, &limit, fp) != -1) {
    if (strcmp(line, "[SBo]\n") == 0 && type == sbo) {
      break;
    }
    else if (strcmp(line, "[SBo]\n") == 0 && type == tz) {
      fclose(fp); free(line); return mlist;
    }
    
    if (line[0] != '#' &&
	line[0] != '\n' &&
	type == tz &&
	strcmp(line, "[Packages]\n") != 0) {
      APPEND
    }
  }
  
  if (type == sbo) {
    // this keeps going from where the getline above stopped
    while (getline(&line, &limit, fp) != -1) {
      if (line[0] != '#' && line[0] != '\n') {
	APPEND
      }
    }
  }
  
  fclose(fp);
  free(line);
  if (mlist != nullptr) {
    mlist[count] = nullptr;
  }
  return mlist;
}
