module main;

import std.stdio;
import commands.list;
import commands.installpkg;
import commands.removepkg;
import commands.help;

int main(string[] args)  {
  
  if (args.length < 2) {  // when the command is missing
    write(help());
    return 1;
  } else {

    switch (args[1]) {
      default:  // anything that is one word or more and isnt a command
        write(help());
        return 1;

      case "list":
      case "l":
        write(list());
        break;

      case "install":
      case "i":
        write(installpkg(args[2..$]));
        break;
    
      case "remove":
      case "r":
        write(removepkg(args[2..$]));
        break;
    
      case "--help":
        write(help());
        break;
    }
  }
  
  return 0;
}
