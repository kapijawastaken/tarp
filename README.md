# tarp - **tar** **p**ackage manager

A package manager for Slackware that will be able to do everything
(at some point in the future).

# TODO:
* installing local packages (done)
* listing local packages (done)
* counting local packages (done)
* removing packages (done)
* installing local packages (done)
* supporting multiple repos at once (done)
* updating the checksums (done)
* updating the gpg signature (done)
* updating the gpg key (done)
* installing new packages (like slackpkg install-new)
* installing remote packages
* upgrading remote packages
* searching for files in packages
* installing SlackBuilds
* automatically installing dependencies for packages and SlackBuilds


# (not very) FAQ

## What is tarp trying to do?
tarp is trying to be a replacement for slackpkg and whatever else you need
bolted on top to install packages and SlackBuilds. It is NOT trying to be a
replacement for pkgtool, and even calls it. However, this may change in the
far future. Rewriting pkgtool in C would be pretty cool.

## Why is it called tarp?
tarp stands for **tar** **p**ackage manager, referencing Slackware packages,
which are tar-based. (.tgz, .txz)

## Why?
tarp mainly serves as my first big project in C. I've been wanting to give
Slackware a proper package manager for a long time now, and have also been
wanting to learn C for a long time, but always just put it off by learning
other languages to make it "easier".

## What can this project be compared to?
In a way, tarp is similar to AUR helpers like yay and paru, as it's a wrapper
around the system package manager but also supports installing SlackBuilds,
which are similar to PKGBUILDs.

# Requirements:
* gcc 15 or above
* make
* libcurl

# Build instructions
```
git clone https://github.com/kapijawastaken/tarp
cd tarp
make
sudo make install
```
