#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10
int particiona(int *v, int inicio, int fim)
{
  int pivot = v[inicio];
  int left = inicio;
  int right = fim;
  while (left < right)
  {
    while (left <= fim && v[left] <= pivot)
    {
      left++;
    }
    while (right > 0 && v[right] > pivot)
    {
      right--;
    }
    if (left < right)
    {
      int tmp = v[left];
      v[left] = v[right];
      v[right] = tmp;
    }
  }
  v[inicio] = v[right];
  v[right] = pivot;
  return right;
}

void quicksort(int *v, int inicio, int fim)
{
  if (fim > inicio)
  {
    int pivot_index = particiona(v, inicio, fim);
    quicksort(v, inicio, pivot_index - 1);
    quicksort(v, pivot_index + 1, fim);
  }
}

int main()
{
  int vector[N];
  srand(10);
  for (int i = 0; i < N; i++)
  {
    vector[i] = rand() % 1000;
  }
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  quicksort(vector, 0, N - 1);
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");

  return 0;
}