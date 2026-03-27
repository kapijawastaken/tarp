char *removepkg(int argc, char **argv) {
  if (argc <= 0) {
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
    asprintf(&result, "");
    int c;
    FILE *fp = popen(cmd, "r");
    free(cmd);
    
    while ((c = fgetc(fp)) != EOF) {
      char *tmp;
      asprintf(&tmp, "%s%c", result, c);
      free(result);
      result = tmp;
    }
    
    pclose(fp);
    return result;
  }
}
