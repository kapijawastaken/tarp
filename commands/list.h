int list() {
  struct dirent **entries;
  int n = scandir("/var/lib/pkgtools/packages", &entries, NULL, alphasort);  

  if (n < 0) {
    fprintf(stderr, "Failed to read /var/lib/pkgtools/packages!\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (strcmp(entries[i]->d_name, ".") != 0 && strcmp(entries[i]->d_name, "..") != 0) {
      printf("%s\n", entries[i]->d_name);
    }
    free(entries[i]);
  }
  
  free(entries);
  return 0;
}
