module commands.help;

string help() {
string help = q"EOS
Usage: tarp <command>
Available commands:
install, i <package>   Installs a local or remote package
list, l                Lists installed packages
count, c               Shows the amount of installed packages
remove, r              Removes a package
--help                 Show this page
EOS"
;
return help;
}
