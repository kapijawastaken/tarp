#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mirrors.h"

static int append(char ***mlist, int *count, char *line) {
  // using pointers here bc we dont want copies of the original vars
  char **tmp = realloc(*mlist, sizeof(char *) * (*count + 2));
  if (tmp == nullptr) { return 1; }
  *mlist = tmp;

  (*mlist)[(*count)++] = strdup(line);
  // operator precedence is weird.
  return 0;
}

char **mirrors(enum PKG type) {
  FILE *fp = fopen("/etc/tarp/mirrors", "r");
  if (!fp) {
    fprintf(stderr, "/etc/tarp/mirrors not found!");
    return nullptr;
  }
  char *line = nullptr;
  char **mlist = nullptr;
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
      if (append(&mlist, &count, line) != 0) {
	fclose(fp); free(line);
	if (mlist != nullptr) { mlist[count] = nullptr; }
	return mlist;
      }
    }
  }
  
  if (type == sbo) {
    // this keeps going from where the getline above stopped
    while (getline(&line, &limit, fp) != -1) {
      if (line[0] != '#' && line[0] != '\n') {
	if (append(&mlist, &count, line) != 0) {
	  fclose(fp); free(line);
	  if (mlist != nullptr) { mlist[count] = nullptr; }
	  return mlist;
	}
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
