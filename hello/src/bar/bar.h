#ifndef BAR_H_
#define BAR_H_

typedef struct Bar {
  int val;
} Bar;

Bar *bar_alloc(void);
int bar_inc(Bar *);
int bar_dec(Bar *);
void bar_free(Bar *);

#endif //BAR_H_
