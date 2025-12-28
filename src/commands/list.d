module commands.list;

import std.file;
import std.array;
import std.algorithm;

string list()
{
    string[] pkgs;
   
    foreach (string name; dirEntries("/var/lib/pkgtools/packages", SpanMode.shallow))
    {
        pkgs ~= name.replace("/var/lib/pkgtools/packages/", "") ~ "\n";
    }
    sort(pkgs);
    return pkgs.join;
}
