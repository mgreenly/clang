#include <stdio.h>

#include "foo/foo.h"
#include "bar/bar.h"

int main() {
  printf("Hello World!\n");
  printf("%d", foo_inc(1));
  printf("%d", bar_dec(2));
  return 0;
}
