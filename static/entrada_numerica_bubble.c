#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 13
void bubble_sort_crescente(int *ptr_vector, int size)
{
  int fim = size - 1;
  int i = 0;
  while (i < fim)
  {
    bool flag = true;

    for (int i = 0; i < fim; i++)
    {
      if (ptr_vector[i] > ptr_vector[i + 1])
      {
        int tmp = ptr_vector[i];
        ptr_vector[i] = ptr_vector[i + 1];
        ptr_vector[i + 1] = tmp;
        flag = false;
      }
    }
    if (flag)
    {
      break;
    }
    fim--;
    i++;
  }
}
void bubble_sort_decrescente(int *ptr_vector, int size)
{
  int fim = size - 1;
  int i = 0;
  while (i < fim)
  {
    bool flag = true;

    for (int i = 0; i < fim; i++)
    {
      if (ptr_vector[i] < ptr_vector[i + 1])
      {
        int tmp = ptr_vector[i];
        ptr_vector[i] = ptr_vector[i + 1];
        ptr_vector[i + 1] = tmp;
        flag = false;
      }
    }
    if (flag)
    {
      break;
    }
    fim--;
    i++;
  }
}

void print_list(int *ptr_vector, int size)
{

  for (int i = 0; i < size; i++)
  {
    printf("%d\t", ptr_vector[i]);
  }

  printf("\n");
}
int main()
{
  int vector[N];
  srand(10);
  // a
  for (int i = 0; i < N; i++)
  {
    vector[i] = i;
  }
  print_list(vector, N);
  bubble_sort_crescente(vector, N);
  print_list(vector, N);

  // b
  for (int i = 0; i < N; i++)
  {
    vector[i] = rand() % 100;
  }
  print_list(vector, N);

  bubble_sort_crescente(vector, N);
  print_list(vector, N);

  // c
  for (int i = 0; i < N; i++)
  {
    vector[i] = i;
  }
  print_list(vector, N);

  bubble_sort_decrescente(vector, N);
  print_list(vector, N);

  return 0;
}