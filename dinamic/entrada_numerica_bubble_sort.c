#include <stdio.h>
#include <stdlib.h>
#include "list_numerica.h"
#define N 13

int main()
{
  List *list = create();
  srand(10);
  // a
  for (ll i = N - 1; i >= 0; i--)
  {
    add_begin_list(list, i);
  }
  print_list(list);
  bubble_sort_crescente(list);
  print_list(list);
  // b
  clean_list(list);
  for (int i = 0; i < N; i++)
  {
    add_begin_list(list, rand() % 100);
  }
  print_list(list);

  bubble_sort_crescente(list);
  print_list(list);
  // c
  clean_list(list);
  for (ll i = N - 1; i >= 0; i--)
  {
    add_begin_list(list, i);
  }
  print_list(list);

  bubble_sort_decrescente(list);
  print_list(list);
  free_list(list);
  return 0;
}