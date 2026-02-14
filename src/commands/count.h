#include <dirent.h>
#include <stdio.h>

int count()
{
    struct dirent **namelist;
    int n = scandir("/var/lib/pkgtools/packages", &namelist, NULL, alphasort);
    return n;
}
