#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "shcmd.h"

int shcmd(enum Mode mode, int argc, char **argv) {

  char *cmd;
  
  if (argc <= 0) {
    help();
    return 1;
  }

  if (mode == r) {
    cmd = "removepkg";
  }
  
  else if (mode == i) {
    cmd = "installpkg";
  }
  
  else {
    fprintf(stderr, "You called shcmd() using an"
	            "unsupported command as input!");
    return 1;
  }

  for (int i = 0; i < argc; i++) {
    char *tmp;
    asprintf(&tmp, "%s %s", cmd, argv[i]);
    if (i > 0) { // because the first iteration points to a string literal
      free(cmd);
    }
    cmd = tmp;
  }
  
  FILE *fp = popen(cmd, "r");
  free(cmd);
  if (!fp) {
    fprintf(stderr, "Failed to open a shell!");
      return 1;
  }
  
  int c; // fgetc returns int, EOF is -1
  while ((c = fgetc(fp)) != EOF) { putchar(c); } // prints fp int by int
  pclose(fp);
  return 0;
}
