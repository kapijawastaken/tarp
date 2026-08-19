#ifndef SHCMD_H
#define SHCMD_H

enum Mode {
  i,
  r
};

int shcmd(enum Mode mode, int argc, char **argv);

// mode can either be r (remove) or i (install)

#endif
