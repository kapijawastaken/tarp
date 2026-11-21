#include "mirrors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MIRRORS 32
#define MAX_MIRRORS_LEN 128

char **mirrors(enum PKG type) {
  FILE *fp = fopen("/etc/tarp/mirrors", "r");
  if (!fp) {
    fprintf(stderr, "/etc/tarp/mirrors not found!");
    return nullptr;
  }

  char **mirrors_arr = calloc(MAX_MIRRORS, sizeof(char *));
  if (!mirrors_arr) {
    fclose(fp);
    return nullptr;
  }

  for (int i = 0; i < MAX_MIRRORS;) {
    char mirror[MAX_MIRRORS_LEN];
    if (fgets(mirror, MAX_MIRRORS_LEN, fp) == nullptr) {
      fclose(fp);
      return mirrors_arr;
    }

    if (strcmp(mirror, "[SBo]\n") == 0 && type == SBO) {
      break; // skips down to the SBO section
    }

    if (strcmp(mirror, "[SBo]\n") == 0 && type == TZ) {
      // when there are no package mirrors
      fclose(fp);
      return mirrors_arr;
    }

    if (mirror[0] != '#' &&
        mirror[0] != '\n' &&
        type == TZ &&
        strcmp(mirror, "[Packages]\n") != 0) {
      mirrors_arr[i] = strdup(mirror);

      if (!mirrors_arr[i]) {
	for (int i = 0; i < MAX_MIRRORS && mirrors_arr[i]; i++) {
	  free(mirrors_arr[i]);
	}
	free(mirrors_arr);
        fclose(fp);
        return nullptr;
      }
      i++;
    }
  }

  if (type == SBO) {
    char mirror[MAX_MIRRORS_LEN];
    for (int i = 0; i < MAX_MIRRORS;) {
      if (fgets(mirror, MAX_MIRRORS_LEN, fp) == nullptr) {
	break;
      }

      if (mirror[0] != '#' && mirror[0] != '\n') {
	mirrors_arr[i] = strdup(mirror);
	i++;
      }
    }

    fclose(fp);
    return mirrors_arr;
  }
  fclose(fp);
  return mirrors_arr;
}
