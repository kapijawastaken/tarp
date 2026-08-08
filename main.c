#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <curl/curl.h>
#include "commands/help.h" // dont move this one.
#include "commands/fnv1a.h" // not this one either.
#include "commands/removepkg.h"
#include "commands/installpkg.h"
#include "commands/list.h"
#include "commands/count.h"
#include "commands/mirrors.h"
#include "commands/update.h"

int main(int argc, char **argv) {
  if (argc <= 1) {
    help();
    return 1;
  }

  else if (strcmp(argv[1], "h") == 0 || strcmp(argv[1], "help") == 0) {
    return help();
  }
  
  else if (strcmp(argv[1], "r") == 0 || strcmp(argv[1], "remove") == 0) {
    return removepkg(argc - 2, argv + 2);
  }

  else if (strcmp(argv[1], "i") == 0 || strcmp(argv[1], "install") == 0) {
    return installpkg(argc - 2, argv + 2);
  }

  else if (strcmp(argv[1], "c") == 0 || strcmp(argv[1], "count") == 0) {
    return count();
  }

  else if (strcmp(argv[1], "u") == 0 || strcmp(argv[1], "update") == 0) {
    return update();
  }
  
  else if (strcmp(argv[1], "l") == 0 || strcmp(argv[1], "list") == 0) {
    return list();
  }

  else {
    help();
    return 1;
  }
}
