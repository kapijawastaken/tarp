module commands.installpkg;

import std.algorithm;
import std.process;

string installpkg(string[] args) {
  if (args.length == 0) {
    return "Usage: tarp install <package>\n";
  }
    
  string packageFile = args[0];
    
  if (packageFile.endsWith(".tgz") || packageFile.endsWith(".txz") || packageFile.endsWith(".tlz") || packageFile.endsWith(".tbz")) {
    return executeShell("installpkg " ~ packageFile).output;
  } else {
    return "Installing package from repository: " ~ packageFile ~ "\n";
  }

}
