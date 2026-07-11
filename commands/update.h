char *update() {
  char **mirrors = pkgmirrors();
  if (mirrors == NULL) {
    return "You don't have any mirrors set!\n"
      "Go and do that by uncommenting one"
      "or more mirrors in /etc/tarp/mirrors.";
  }

  char *checksum_path = NULL;  
  for (int i = 0; mirrors[i] != NULL; i++) {
    if (strncmp(mirrors[i], "https://", 8) != 0 &&
        strncmp(mirrors[i], "http://", 7) != 0 &&
	strncmp(mirrors[i], "ftp://", 6) != 0) {
      return NULL;
    }

    asprintf(&checksum_path, "%s/CHECKSUMS.md5", tmpdir(mirrors[i]));
    if (access(checksum_path, F_OK) == -1) {
      // nothing yet
    }
    free(checksum_path);
  }
  return; // nothing yet either
}

char *tmpdir(char *str) {
  static char output[19];
  unsigned int h = fnv1a(str);
  snprintf(output, sizeof(output), "/tmp/tarp/%08x", h);
  return output;
}
