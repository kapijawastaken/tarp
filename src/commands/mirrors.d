module commands.mirrors;

import std.stdio;
import std.file;
import std.array;
import std.algorithm;
import std.string;

string[] mirrors(string arg) {
  string[] mirrors = readText("/etc/tarp/mirrors.toml").splitLines;
  string[] slackwaremirrors;
  string[] sbomirrors;
  long slackwarepos = mirrors.countUntil("[Packages]");
  long sbopos = mirrors.countUntil("[SBo]");  
  
  foreach (line; mirrors[0 .. (sbopos == -1 ? $ : sbopos)]) {
    if (!line.empty && !line.startsWith("#") && !line.startsWith("["))
      slackwaremirrors ~= line;
  }
  
  
  if (slackwaremirrors.empty) {
    writeln("You don't have any mirrors set!\n" ~
            "Go and do that by uncommenting one or more mirrors in /etc/tarp/mirrors.toml.");
  }
  
  
  if (sbopos != -1) {
    foreach (line; mirrors[sbopos .. $]) {
      if (!line.empty && !line.startsWith("#") && !line.startsWith("["))
        sbomirrors ~= line;
    }
  }
  
  if (arg == "slackware")
    return slackwaremirrors;
  else if (arg == "sbo")
    return sbomirrors;
  else
    return [];
}
