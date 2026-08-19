#include <stdio.h>
#include <string.h>
#include "commands/help.h"
#include "commands/shcmd.h"
#include "commands/list.h"
#include "commands/count.h"
#include "commands/update.h"
#include "commands/repoid.h"

int main(int argc, char **argv) {
  if (argc <= 1) {
    help();
    return 1;
  }

  else if (strcmp(argv[1], "h") == 0 || strcmp(argv[1], "help") == 0) {
    return help();
  }

  else if (strcmp(argv[1], "ri") == 0 || strcmp(argv[1], "repoid") == 0) {
    return repoid(argv + 2);
  }

  else if (strcmp(argv[1], "r") == 0 || strcmp(argv[1], "remove") == 0) {
    return shcmd(r, argc - 2, argv + 2);
  }

  else if (strcmp(argv[1], "i") == 0 || strcmp(argv[1], "install") == 0) {
    return shcmd(i, argc - 2, argv + 2);
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
