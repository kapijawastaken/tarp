module commands.update;

import std.stdio;
import std.net.curl;
import std.regex;
import commands.mirrors;
import std.digest;
import std.digest.sha;
import std.string;
import std.file;
import std.algorithm.comparison;


string update() 
{
    foreach (r; slackwaremirrors) 
    {
        if (r.startsWith("https://") || r.startsWith("ftp://"))
        {
            if (!exists("/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5"))
            {
                mkdirRecurse("/tmp/tarp/" ~ tmpdir(r));
                download(r ~ "CHECKSUMS.md5", "/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5");
                writeln("Downloaded checksum for mirror " ~ r ~ ".");
            } 
            else 
            {
                string checksum = get(r ~ "CHECKSUMS.md5").idup;

                if (cmp(checksum, readText("/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5")) == 0) 
                {
                    writeln("Nothing to update for mirror " ~ r ~ ".");
                }
                else 
                {
                    download(r ~ "CHECKSUMS.md5", "/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5");
                    writeln("Updated checksum for mirror " ~ r ~ ".");
                }

            }
        }
    }
    return "Update finished.";
}


string tmpdir(string url) 
{
    return sha256Of(url)[0 .. 8].toHexString.toLower;
}
