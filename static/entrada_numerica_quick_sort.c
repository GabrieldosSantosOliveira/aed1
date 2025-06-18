#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
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
  int vector[N];
  srand(10);
  //a
  for (int i = 0; i < N; i++)
  {
    vector[i] = i;
  }
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  quicksort(vector, sizeof(int), N, comparador_crescente);
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  //b
  for (int i = 0; i < N; i++)
  {
    vector[i] = rand() % 100;
  }
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  quicksort(vector, sizeof(int), N, comparador_crescente);
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  //c
  for (int i = 0; i < N; i++)
  {
    vector[i] = i;
  }
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  quicksort(vector, sizeof(int), N, comparador_decrescente);
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  return 0;
}