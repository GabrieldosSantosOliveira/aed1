#include "quick_sort.h"
void swap(void *a, void *b, int size_type)
{
  char *x = (char *)a;
  char *y = (char *)b;
  for (int i = 0; i < size_type; i++)
  {
    char tmp = *(x + i);
    *(x + i) = *(y + i);
    *(y + i) = tmp;
  }
}

int particiona(void *v, int inicio, int fim, Comparator comparator, int size_type)
{
  char *vector = (char *)v;
  char *pivot = vector + (inicio * size_type);
  int left = inicio;
  int right = fim;
  while (left < right)
  {
    while (left <= fim && comparator(vector + (left * size_type), pivot) <= 0)
    {
      left++;
    }
    while (right > 0 && comparator(vector + (right * size_type), pivot) == 1)
    {
      right--;
    }
    if (left < right)
    {
      swap(vector + (left * size_type), vector + (right * size_type), size_type);
    }
  }
  swap(pivot, vector + (right * size_type), size_type);
  return right;
}

void quicksort_impl(void *v, int inicio, int fim, Comparator comparator, int size_type)
{
  if (fim > inicio)
  {
    int pivot_index = particiona(v, inicio, fim, comparator, size_type);
    quicksort_impl(v, inicio, pivot_index - 1, comparator, size_type);
    quicksort_impl(v, pivot_index + 1, fim, comparator, size_type);
  }
}
void quicksort(void *v, int size_type, int size_v, Comparator comparator)
{
  quicksort_impl(v, 0, size_v - 1, comparator, size_type);
}