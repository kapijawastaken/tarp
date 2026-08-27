#ifndef MIRRORS_H
#define MIRRORS_H

enum PKG {
  tz,
  sbo
};
// tz = tgz, txz, etc

char **mirrors(enum PKG type);

#endif
