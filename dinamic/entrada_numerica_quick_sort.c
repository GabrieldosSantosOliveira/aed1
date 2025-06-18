#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define N 13

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
  quick_sort(list);
  print_list(list);
  free_list(list);
  return 0;
}