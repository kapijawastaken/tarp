module commands.installpkg;

import std.algorithm;
import std.process;
import commands.help;
import commands.downloadpkg;

string installpkg(string[] args)
{
    if (args.length == 0)
    {
        return help;
    }
      
    if (args[0].endsWith(".tgz") || args[0].endsWith(".txz") || args[0].endsWith(".tlz") || args[0].endsWith(".tbz"))
    {
        return executeShell("installpkg " ~ args[0]).output;
    } 
    else 
    {
        writeln("Installing package from repository: " ~ args[0]);
        downloadpkg(args[]);
        return executeShell("installpkg " ~ args[0]).output;    
    }
}
