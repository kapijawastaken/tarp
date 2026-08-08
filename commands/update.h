char *tmpdir(char *str) {
  static char output[19]; // "/tmp/tarp/" (10) + 8 hex chars + null = 19
  unsigned int h = fnv1a(str);
  snprintf(output, sizeof(output), "/tmp/tarp/%08x", h);
  return output;
}

int update() {
  char **mirrors = pkgmirrors();
  char *checksum_path = NULL, *signature_path = NULL;
  char repoid[9];
  if (mirrors == NULL) {
    fprintf(stderr, "%s\n",
	    "You don't have any mirrors set!\n"
	    "Go and do that by uncommenting one "
	    "or more mirrors in /etc/tarp/mirrors.");
    return 1;
  }
  for (int i = 0; mirrors[i] != NULL; i++) {
    mirrors[i][strcspn(mirrors[i], "\n")] = '\0';
    snprintf(repoid, 9, "%08x", fnv1a(mirrors[i]));
    
    if (strncmp(mirrors[i], "https://", 8) != 0 &&
        strncmp(mirrors[i], "http://", 7) != 0 &&
	strncmp(mirrors[i], "ftp://", 6) != 0) {
      fprintf(stderr, "%s is a local repo, running "
	      "tarp update is unneccessary.\n", repoid);
      continue;
    }
    
    asprintf(&checksum_path, "%s/CHECKSUMS.md5", tmpdir(mirrors[i]));
    if (access(tmpdir(mirrors[i]), W_OK) == -1) {
      if (mkdir("/tmp/tarp", 0755) == -1 && errno != EEXIST) { // rwx,rx,rx
	fprintf(stderr, "Failed to create temporary directory /tmp/tarp!\n");
	return 1;
      }
      if (mkdir(tmpdir(mirrors[i]), 0755) == -1 && errno != EEXIST) { // rwx,rx,rx
	fprintf(stderr, "Failed to create temporary directory %s!\n",
		tmpdir(mirrors[i]));
	return 1;
      }
    }
    
    char *checksum_url = NULL;
    asprintf(&checksum_url, "%sCHECKSUMS.md5", mirrors[i]);
    
  checksum:
    if (download(checksum_url, checksum_path) == 1) {
      fprintf(stderr, "Checksum download of %s failed!\n", repoid);
      printf("Retry? [Y/n] ");
      int choice = getchar();
      int c;
      if (choice != '\n') {
	while ((c = getchar()) != '\n' && c != EOF);
	// only discard if there's more on the line
      }
      if (choice == 'y' || choice == 'Y' || choice == '\n') { goto checksum; }
    }
    free(checksum_url);
    free(checksum_path);

    asprintf(&signature_path, "%s/CHECKSUMS.md5.asc", tmpdir(mirrors[i]));
    if (access(tmpdir(mirrors[i]), W_OK) == -1) {
      if (mkdir("/tmp/tarp", 0755) == -1 && errno != EEXIST) { // rwx,rx,rx
	fprintf(stderr, "Failed to create temporary directory /tmp/tarp!\n");
	return 1;
      }
      if (mkdir(tmpdir(mirrors[i]), 0755) == -1 && errno != EEXIST) { // rwx,rx,rx
	fprintf(stderr, "Failed to create temporary directory %s!\n",
		tmpdir(mirrors[i]));
	return 1;
      }
    }

    char *signature_url = NULL;
    asprintf(&signature_url, "%sCHECKSUMS.md5.asc", mirrors[i]);
    
  signature:
    if (download(signature_url, signature_path) == 1) {
      fprintf(stderr, "Signature download of %s failed!\n", repoid);
      printf("Retry? [Y/n] ");
      int choice = getchar();
      int c;
      if (choice != '\n') {
	while ((c = getchar()) != '\n' && c != EOF);
	// only discard if there's more on the line
      }
      if (choice == 'y' || choice == 'Y' || choice == '\n') { goto signature; }
    }
    free(signature_url);
    free(signature_path);
  }
  return 0;
}
