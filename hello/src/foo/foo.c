#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "foo.h"

Foo *foo_alloc(void) {
  Foo *foo = malloc(sizeof(Foo));
  if (foo == NULL) {
    fprintf(stderr, "Error, malloc failed: %s#%d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  return foo;
}

int foo_inc(Foo *foo) {
  foo->val = foo->val + 1;
  return foo->val;
}

int foo_dec(Foo *foo) {
  foo->val = foo->val - 1;
  return foo->val;
}

void foo_free(Foo *foo) {
  free(foo);
}
