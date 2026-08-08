int help() {
  char *helptext = "Usage: tarp <command>\n" 
    "Available commands:\n" 
    "install, i <package>   Installs a local or remote package\n"
    "repoid, ri <repoID>    Prints the repo belonging to the repoID\n"
    "list, l                Lists installed packages "
    "(It's recommended to pipe this into a pager like less)\n"
    "count, c               Shows the amount of installed packages\n"
    "remove, r <package>    Removes a package\n" 
    "update, u              Updates the package list\n" 
    "updategpg, ug          Updates the GPG keys\n" 
    "help, h                Shows this page\n";
  printf("%s", helptext);
  return 0;
}
