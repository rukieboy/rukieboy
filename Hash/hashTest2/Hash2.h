#include <search.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static char* keys[] = { "ciro", "hue", "br", "haha", "Lol" };
static char* values[] = { "cccc", "hhhh", "bbbb", "aaa", "oooo" };

typedef struct table_t {
  struct hsearch_data htab;
  size_t size;
} table_t;

#define TABLE_T_INITIALIZER                                                    \
  (table_t)                                                                    \
  {                                                                            \
    .htab = (struct hsearch_data){ 0 }, .size = 0                              \
  }
