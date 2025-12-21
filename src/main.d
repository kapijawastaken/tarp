module main;

import std.stdio;
import commands.list;
import commands.count;
import commands.installpkg;
import commands.removepkg;
import commands.help;
import commands.mirrors;

int main(string[] args)  {
  
  writeln(mirrors("sbo"));  // setup

  if (args.length < 2) {  // when the command is missing
    write(help());
    return 1;
  } else {

    switch (args[1]) {
      default:  // anything that is one word or more and isnt a command
        write(help);
        return 1;

      case "list":
      case "l":
        write(list);
        break;

      case "count":
      case "c":
        writeln(count);
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
        write(help);
        break;
    }
  }
  
  return 0;
}
