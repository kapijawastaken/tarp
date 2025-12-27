module commands.mirrors;

import std.stdio;
import std.file;
import std.array;
import std.algorithm;
import std.string;

string[] slackwaremirrors()
{
    string[] mirrors = readText("/etc/tarp/mirrors.toml").splitLines;
    string[] slackwarearr;
    long slackwarepos = mirrors.countUntil("[Packages]");
    long sbopos = mirrors.countUntil("[SBo]");  

    foreach (line; mirrors[0 .. (sbopos == -1 ? $ : sbopos)])
    {
        if (!line.empty && !line.startsWith("#") && !line.startsWith("["))
            slackwarearr ~= line;
    }
    
    if (slackwarearr.empty)
    {
        writeln("You don't have any mirrors set!\n" ~
                "Go and do that by uncommenting one or more mirrors in /etc/tarp/mirrors.toml.");
    }
    return slackwarearr;
}

string[] sbomirrors()
{
    string[] mirrors = readText("/etc/tarp/mirrors.toml").splitLines;
    string[] sboarr;
    long slackwarepos = mirrors.countUntil("[Packages]");
    long sbopos = mirrors.countUntil("[SBo]");  
  
    if (sbopos != -1)
    {
        foreach (line; mirrors[sbopos .. (sbopos < slackwarepos ? slackwarepos : $)])
        {
            if (!line.empty && !line.startsWith("#") && !line.startsWith("["))
                sboarr ~= line;
        }
    }
    return sboarr;
}
