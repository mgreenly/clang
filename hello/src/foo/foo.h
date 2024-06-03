#ifndef FOO_H_
#define FOO_H_

typedef struct Foo {
  int val;
} Foo;

Foo *foo_alloc(void);
int foo_inc(Foo *);
int foo_dec(Foo *);
void foo_free(Foo *);

#endif //FOO_H_
