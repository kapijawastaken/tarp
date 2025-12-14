module commands.count;

import std.file;

int count() {
  int count = 0;
  foreach (string name; dirEntries("/var/lib/pkgtools/packages", SpanMode.shallow)) {
    count++;
  }
  return count;
}
