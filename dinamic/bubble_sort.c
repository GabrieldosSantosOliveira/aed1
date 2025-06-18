
#include "bubble_sort.h"
void swap(List *v, int index_a, int index_b)
{
  int x = find_by_index(v, index_a);
  remove_by_index_list(v, index_a);
  add_by_index_list(v, x, index_a + 1);
}

void bubble_sort(List *v, int size_vector, Comparator comparator)
{
  int fim = size_vector;
  while (true)
  {
    bool flag = true;
    for (int i = 0; i < size_vector - 1; i++)
    {
      int a = find_by_index(v, i);
      int b = find_by_index(v, i + 1);
      if (comparator(&a, &b) == 1)
      {
        swap(v, i, i + 1);
        flag = false;
      }
    }
    if (flag)
    {
      break;
    }
    fim--;
  }
}