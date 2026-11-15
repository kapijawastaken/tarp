#ifndef UPDATE_H
#define UPDATE_H

enum update_type {
  NORMAL,
  GPG
};

int update(enum update_type type);

#endif
