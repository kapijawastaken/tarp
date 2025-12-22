module commands.downloadpkg;

import std.net.curl;
import commands.help;
import std.file;

string downloadpkg(string[] args) {
  if (args.length == 0) {
    return help;
  } else {
    // download stuff
  }
  
  return "download";
}
