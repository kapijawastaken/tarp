module commands.list;

import std.file;
import std.array;

string list()
{
    string list;
   
    foreach (string name; dirEntries("/var/lib/pkgtools/packages", SpanMode.shallow))
    {
        list ~= name.replace("/var/lib/pkgtools/packages/", "") ~ "\n";
    }
    return list;
}
