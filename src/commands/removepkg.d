module commands.removepkg;

import std.algorithm;
import std.process;
import commands.help;

string removepkg(string[] args) {
  if (args.length == 0) {
    return help();
  } else {
  string packageFile = args[0];
  return executeShell("removepkg " ~ packageFile).output;
  }
}
