int repoid(char **input) {
  if (input[0] == NULL) {
    help();
    return 1;
   }
  char *entered = strdup(input[0]);
  char **mirrors = pkgmirrors();
  if (mirrors == NULL) {
    fprintf(stderr, "No repos available!\n");
    free(entered);
    return 1;
  }
  for (int i = 0; mirrors[i] != NULL; i++) {
    char tmp[9];
    snprintf(tmp, 9, "%08x", fnv1a(mirrors[i]));
    if (strcmp(entered, tmp) == 0) {
      free(entered);
      printf("%s", mirrors[i]);
      return 0;
    }
  }
  free(entered);
  fprintf(stderr, "Entered RepoID doesn't match any repos!\n");
  return 1;
}
