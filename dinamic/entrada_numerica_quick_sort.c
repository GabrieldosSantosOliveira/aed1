#include <stdio.h>
#include <stdlib.h>
#include "list_numerica.h"
#define N 13

int main()
{
  List *list = create();
  srand(10);
  // a
  for (int i = 0; i < N; i++)
  {
    add_end_list(list, i);
  }
  print_list(list);
  quick_sort_crescente(list);
  print_list(list);
  // b
  clean_list(list);
  for (int i = 0; i < N; i++)
  {
    add_end_list(list, rand() % 100);
  }
  print_list(list);

  quick_sort_crescente(list);
  print_list(list);
  // c
  clean_list(list);
  for (int i = 0; i < N; i++)
  {
    add_by_index_list(list, i, i);
  }
  print_list(list);

  quick_sort_decrescente(list);
  print_list(list);

  return 0;
}