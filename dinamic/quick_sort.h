#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include"list.h"
#include <stdbool.h>
// return 1 if a > b
// return 0 if a = b
// return -1 if a < b
typedef int (*Comparator)(const void *const a, const void *const b);
void quicksort(List *v, int inicio, int fim);

#endif