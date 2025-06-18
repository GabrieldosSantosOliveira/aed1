#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bubble_sort.h"
#define N 13

int comparador_crescente(const void *const a, const void *const b)
{
  const int *const x = (const int *const)a;
  const int *const y = (const int *const)b;

  if (*x == *y)
  {
    return 0;
  }
  else if (*x < *y)
  {
    return -1;
  }
  else if (*x > *y)
  {
    return 1;
  }
}
int comparador_decrescente(const void *const a, const void *const b)
{
  const int *const x = (const int *const)a;
  const int *const y = (const int *const)b;

  if (*x == *y)
  {
    return 0;
  }
  else if (*x < *y)
  {
    return 1;
  }
  else if (*x > *y)
  {
    return -1;
  }
}
int main()
{
  List *list = create();
  srand(10);
  // a
  for (int i = 0; i < N; i++)
  {
    add_by_index_list(list, i, i);
  }
  print_list(list);
  bubble_sort(list, size(list), comparador_crescente);
  print_list(list);
  // b
  clean_list(list);
  for (int i = 0; i < N; i++)
  {
    add_by_index_list(list, rand() % 100, i);
  }
  print_list(list);

  bubble_sort(list, N, comparador_crescente);
  print_list(list);
  // c
  clean_list(list);
  for (int i = 0; i < N; i++)
  {
    add_by_index_list(list, i, i);
  }
  print_list(list);

  bubble_sort(list, N, comparador_decrescente);
  print_list(list);

  return 0;
}