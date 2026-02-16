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
                writeln("Downloaded checksums for mirror " ~ r ~ " to /tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5.");
                download(r ~ "CHECKSUMS.md5.asc", "/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5.asc");
                writeln("Downloaded GPG signature for mirror " ~ r ~ " to /tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5.asc.");
            }
            else 
            {
                string checksum = get(r ~ "CHECKSUMS.md5").idup;
                string signature = get(r ~ "CHECKSUMS.md5.asc").idup;

                if (cmp(checksum, readText("/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5")) == 0 && 
                    cmp(signature, readText("/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5.asc")) == 0) 
                {
                    string nothing = "Nothing to update for mirror " ~ r ~ ".";
                    return nothing;
                }
                else 
                {
                    download(r ~ "CHECKSUMS.md5", "/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5");
                    writeln("Updated checksums for mirror " ~ r ~ " at /tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5.");
                    download(r ~ "CHECKSUMS.md5.asc", "/tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5.asc");
                    writeln("Updated GPG signature for mirror " ~ r ~ " at /tmp/tarp/" ~ tmpdir(r) ~ "/CHECKSUMS.md5.asc.");
                }
            }
        }
    }
    if (slackwaremirrors.empty)
        return "You don't have any mirrors set!\nGo and do that by uncommenting one or more mirrors in /etc/tarp/mirrors.toml.";
    else
        return "Update finished.";
}


string tmpdir(string url) 
{
    return sha256Of(url)[0 .. 8].toHexString.toLower;
}
