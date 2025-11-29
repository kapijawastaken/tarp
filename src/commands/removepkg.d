module commands.removepkg;

import std.algorithm;
import std.process;

string removepkg(string[] args) {
  if (args.length == 0) {
    return "Usage: tarp remove <package>\n";
  } else {
  string packageFile = args[0];
  return executeShell("removepkg " ~ packageFile).output;
  }
}
