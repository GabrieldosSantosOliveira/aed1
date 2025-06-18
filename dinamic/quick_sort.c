#include "quick_sort.h"

void swap(List *v, int index_a, int index_b)
{
  if (index_a < index_b)
  {
    int tmp = index_a;
    index_a = index_b;
    index_b = index_a;
  }
  int x = find_by_index(v, index_a);
  remove_by_index_list(v, index_a);
  add_by_index_list(v, x, index_b);
  int y = find_by_index(v, index_b);
  remove_by_index_list(v, index_b);
  add_by_index_list(v, x, index_a);
}

int particiona(List *v, int inicio, int fim)
{
  int pivot = find_by_index(v, inicio);
  int left = inicio;
  int right = fim;
  while (left < right)
  {
    while (left <= fim && find_by_index(v, left) <= pivot)
    {
      left++;
    }
    while (right > 0 && find_by_index(v, right) > pivot)
    {
      right--;
    }
    if (left < right)
    {
      swap(v, left, right);
    }
  }
  swap(v, inicio, right);
  return right;
}

void quicksort(List *v, int inicio, int fim)
{
  if (fim > inicio)
  {
    int pivot_index = particiona(v, inicio, fim);
    quicksort(v, inicio, pivot_index - 1);
    quicksort(v, pivot_index + 1, fim);
  }
}
