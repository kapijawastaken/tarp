char **list() {
  struct dirent **entries;
  int n = scandir("/var/lib/pkgtools/packages", &entries, NULL, alphasort);  
  if (n < 0) { return NULL; }
  char **names = malloc((n + 1) * sizeof(char *));
  int j = 0;

  for (int i = 0; i < n; i++) {

    if (strcmp(entries[i]->d_name, ".") != 0 && strcmp(entries[i]->d_name, "..") != 0) {
      names[j] = strdup(entries[i]->d_name);
      j++;
    }

    free(entries[i]);
  }
  
  free(entries);
  names[j] = NULL;
  return names;
}
