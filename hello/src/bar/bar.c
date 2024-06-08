#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bar.h"

Bar *bar_alloc(void) {
  Bar *bar = malloc(sizeof(Bar));
  if (bar == NULL) {
    fprintf(stderr, "Error, malloc failed: %s#%d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  return bar;
}

int bar_inc(Bar *bar) {
  bar->val = bar->val + 1;
  return bar->val;
}

int bar_dec(Bar *bar) {
  bar->val = bar->val - 1;
  return bar->val;
}

void bar_free(Bar *bar) { free(bar); }
