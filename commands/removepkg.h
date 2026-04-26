char *removepkg(int argc, char **argv) {
  if (argc <= 0) {
    // main() frees this function, so we need it on the heap.
    char *out;
    asprintf(&out, "%s", help());
    return out;
  }
  else {
    char *cmd;
    asprintf(&cmd, "removepkg");

    for (int i = 0; i < argc; i++) {
      char *tmp;
      asprintf(&tmp, "%s %s", cmd, argv[i]);
      free(cmd);
      cmd = tmp;
    }
    
    char *result;
    asprintf(&result, "%s", ""); // asprintf needs at least 2 args
    int c;
    FILE *fp = popen(cmd, "r");
    free(cmd);
    
    while ((c = fgetc(fp)) != EOF) {
      // here we append the data stream c to result.
      char *tmp;
      asprintf(&tmp, "%s%c", result, c);
      free(result);
      result = tmp;
    }
    
    pclose(fp);
    return result;
  }
}
