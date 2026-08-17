#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mirrors.h"

char **pkgmirrors() {
  FILE *fp = fopen("/etc/tarp/mirrors", "r");
  if (!fp) {
    fprintf(stderr, "/etc/tarp/mirrors not found!");
    return NULL;
  }
  char *line = NULL;
  size_t limit = 0; // getline() allocates this for us
  char **mirrors = NULL, **tmp = NULL;
  int count = 0;
  while (getline(&line, &limit, fp) != -1) {
    if (strcmp(line, "[SBo]\n") == 0) { fclose(fp); free(line); return mirrors; }
    if (line[0] != '#' &&
	line[0] != '\n' &&
	strcmp(line, "[Packages]\n") != 0) {
      tmp = realloc(mirrors, sizeof(char*) * (count + 2));
      if (tmp == NULL) { fclose(fp); free(line); return mirrors; }
      mirrors = tmp;
      mirrors[count++] = strdup(line);
    }
  }
  fclose(fp);
  free(line);
  if (mirrors != NULL) {
    mirrors[count] = NULL;
  }
  return mirrors;
}

char **sbomirrors() {
  FILE *fp = fopen("/etc/tarp/mirrors", "r");
  if (!fp) {
    fprintf(stderr, "/etc/tarp/mirrors not found!");
    return NULL;
  }  
  char *line = NULL;
  size_t limit = 0; // getline() allocates this for us
  char **mirrors = NULL, **tmp = NULL;
  int count = 0;
  while (getline(&line, &limit, fp) != -1) { // this seeks for [SBo]
    if (strcmp(line, "[SBo]\n") == 0) { break; }
  }
  while (getline(&line, &limit, fp) != -1) { // this keeps going from where the one above stopped
    if (line[0] != '#' && line[0] != '\n') {
      tmp = realloc(mirrors, sizeof(char*) * (count + 2));
      if (tmp == NULL) { fclose(fp); free(line); return mirrors; }
      mirrors = tmp;
      mirrors[count++] = strdup(line);
    }
  }
  fclose(fp);
  free(line);
  if (mirrors != NULL) {
    mirrors[count] = NULL;
  }  
  return mirrors;
}

