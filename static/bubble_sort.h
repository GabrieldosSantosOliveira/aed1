#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

// return 1 if a > b
// return 0 if a = b
// return -1 if a < b
typedef int (*Comparator)(const void *const a, const void *const b);
void bubble_sort(void *v, int size_type, int size_vector, Comparator comparator);

#endif