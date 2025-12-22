# tarp - **tar** **p**ackage manager
A package manager for Slackware that does everything (in the future), including:
* installing local packages (done)
* listing local packages (done)
* counting local packages (done)
* removing packages (done)
* installing remote packages (to do)
* installing SlackBuilds (to do)
* automatically installing dependencies for packages and SlackBuilds (to do)
* supporting multiple repos at once (done)

# Requirements:
* gdc
* libcurl

# Build instructions
```
git clone https://github.com/kapijawastaken/tarp
cd tarp
make
sudo make install
```

# FAQ

## Why should you use tarp over other tools like slpkg?
tarp supports searching, downloading and installing packages AND SlackBuilds from multiple repos, unlike [slpkg](https://gitlab.com/dslackw/slpkg/-/issues?sort=created_date&state=closed&first_page_size=20&show=eyJpaWQiOiIxOTgiLCJmdWxsX3BhdGgiOiJkc2xhY2t3L3NscGtnIiwiaWQiOjE3NTUwNDk4Nn0%3D).

## Why is it written in D instead of a more commonly used language like C or Bash?
D handles strings well, has pleasant syntax, and is fast enough.

## Why is it called tarp?
tarp stands for **tar** **p**ackage manager, referencing Slackware packages, which are tar-based. (.tgz, .txz)

## What can this project be compared to?
In a way, tarp is similar to AUR helpers like yay and paru, as it's a wrapper around the system package manager but also supports installing SlackBuilds, which are similar to PKGBUILDs.