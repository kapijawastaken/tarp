#include <dirent.h>
#include <stdlib.h>
int count() {
  struct dirent **entries;
  int n = scandir("/var/lib/pkgtools/packages", &entries, NULL, NULL);
  for (int i = 0; i < n; i++) {
    free(entries[i]);
  }
  free(entries);
  return n - 2; // n - 2 because of . and ..
}
