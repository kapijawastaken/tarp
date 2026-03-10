#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
int count() {
  struct dirent **entries;
  int n = scandir("/var/lib/pkgtools/packages", &entries, NULL, NULL);
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    free(entries[i]);
  }
  free(entries);
  return n;
}
