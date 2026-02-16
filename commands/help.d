module commands.help;

string help()
{
    string help = "Usage: tarp <command>\n" ~
                  "Available commands:\n" ~
                  "install, i <package>   Installs a local or remote package\n" ~
                  "list, l                Lists installed packages\n" ~
                  "count, c               Shows the amount of installed packages\n" ~
                  "remove, r <package>    Removes a package\n" ~
                  "update, u              Updates the package list\n" ~
                  "updategpg, ug          Updates the GPG keys\n" ~
                  "help, h, --help, -h    Shows this page\n";
    return help;
}
