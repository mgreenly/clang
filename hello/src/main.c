#include <stdio.h>

#include "foo/foo.h"
#include "bar/bar.h"

int main() {
  printf("Hello World!\n");
  printf("%d\n", foo_inc(1));
  printf("%d\n", bar_dec(3));
  return 0;
}
