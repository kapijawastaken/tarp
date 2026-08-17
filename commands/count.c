#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "count.h"

int count() {
  struct dirent **entries;
  int n = scandir("/var/lib/pkgtools/packages", &entries, NULL, NULL);

  if (n < 0) {
    fprintf(stderr, "Failed to read /var/lib/pkgtools/packages!\n");
    return 1;
  }
  
  for (int i = 0; i < n; i++) { free(entries[i]); }
  free(entries);
  printf("%d\n", n - 2); // n - 2 because of . and ..
  return 0;
}
