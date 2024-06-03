#include <stdio.h>

#include "foo/foo.h"

int main() {
  printf("Hello!\n");

  struct Foo *foo = foo_alloc();
  foo->val = 37;

  printf("%d\n", foo_inc(foo));
  printf("%d\n", foo_inc(foo));
  printf("%d\n", foo_inc(foo));
  printf("%d\n", foo_dec(foo));
  printf("%d\n", foo_dec(foo));
  printf("%d\n", foo_dec(foo));
  foo_free(foo);

  printf("Goodbye!\n");
  return 0;
}
