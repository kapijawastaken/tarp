#ifndef MIRRORS_H
#define MIRRORS_H

enum PKG {
  TZ,
  SBO
};
// tz = tgz, txz, etc

char **mirrors(enum PKG type);

#endif
