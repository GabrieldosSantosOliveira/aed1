
#include "bubble_sort.h"
#include <stdbool.h>

void bubble_sort(void *v, int size_type, int size_vector, Comparator comparator)
{
  char *vet_pointer = (char *)v;
  int fim = size_vector;
  while (true)
  {
    bool flag = true;

    for (int i = 0; i < fim - 1; i++)
    {
      char *a = vet_pointer + (i * size_type);
      char *b = vet_pointer + ((i + 1) * size_type);
      if (comparator(a, b) == 1)
      {
        for (int j = 0; j < size_type; j++)
        {
          char tmp = *(a + j);
          *(a + j) = *(b + j);
          *(b + j) = tmp;
        }
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