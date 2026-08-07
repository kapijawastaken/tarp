# tarp - **tar** **p**ackage manager

A package manager for Slackware that does everything (in the future), including:
* installing local packages (done)
* listing local packages (done)
* counting local packages (done)
* removing packages (done)
* updating the checksums (done for d)
* updating the gpg signature (done for d)
* updating the gpg key (to do)
* installing remote packages (to do)
* installing SlackBuilds (to do)
* automatically installing dependencies for packages and SlackBuilds (to do)
* supporting multiple repos at once (done)
* c rewrite (to do, priority)
* handling errors properly (stderr) (top priority rn)

# (not very) FAQ

## What is tarp trying to do?
tarp is trying to be a replacement for slackpkg and whatever else you need bolted on top to install packages and SlackBuilds. It is NOT trying to be a replacement for pkgtool, and even calls it.

## Why should you use tarp over other tools like slpkg or slackpkgplus?
tarp supports searching, downloading and installing packages AND SlackBuilds from multiple repos, unlike other tools.

## Why is it called tarp?
tarp stands for **tar** **p**ackage manager, referencing Slackware packages, which are tar-based. (.tgz, .txz)

## What can this project be compared to?
In a way, tarp is similar to AUR helpers like yay and paru, as it's a wrapper around the system package manager but also supports installing SlackBuilds, which are similar to PKGBUILDs.

# Requirements:
* gdc
* libcurl

# Build instructions for the new C version (recommended)
```
git clone https://github.com/kapijawastaken/tarp
cd tarp
make c
sudo make install
```

# Build instructions for the old D version (abandoned, perhaps broken)
```
git clone https://github.com/kapijawastaken/tarp
cd tarp
make
sudo make install
```