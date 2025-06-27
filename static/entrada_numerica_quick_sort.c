#include <stdio.h>
#include <stdlib.h>
#define N 10LL
typedef long long ll;

ll pivo_rand(ll inicio, ll fim)
{
  return (rand() % (fim - inicio + 1)) + inicio;
}
ll partition_crescente(int *v, ll begin, ll end)
{
  ll index_p = pivo_rand(begin, end);
  int tmp;

  tmp = v[begin];
  v[begin] = v[index_p];
  v[index_p] = tmp;

  int pivot = v[begin];
  ll left = begin + 1;
  for (ll i = begin + 1; i <= end; i++)
  {
    if (v[i] < pivot)
    {
      tmp = v[i];

      v[i] = v[left];
      v[left] = tmp;
      left++;
    }
  }

  tmp = v[begin];
  v[begin] = v[left - 1];
  v[left - 1] = tmp;

  return left - 1;
}

void quicksort_crescente(int *v, ll begin, ll end)
{
  if (end > begin)
  {
    ll pivot_index = partition_crescente(v, begin, end);
    quicksort_crescente(v, begin, pivot_index - 1);
    quicksort_crescente(v, pivot_index + 1, end);
  }
}

int partition_decrescente(int *v, ll begin, ll end)
{
  ll index_p = pivo_rand(begin, end);
  int tmp;

  tmp = v[begin];
  v[begin] = v[index_p];
  v[index_p] = tmp;

  int pivot = v[begin];
  ll left = begin + 1;
  for (ll i = begin + 1; i <= end; i++)
  {
    if (v[i] > pivot)
    {
      tmp = v[i];

      v[i] = v[left];
      v[left] = tmp;
      left++;
    }
  }

  tmp = v[begin];
  v[begin] = v[left - 1];
  v[left - 1] = tmp;

  return left - 1;
}

void quicksort_decrescente(int *v, ll begin, ll end)
{
  if (end > begin)
  {
    ll pivot_index = partition_decrescente(v, begin, end);
    quicksort_decrescente(v, begin, pivot_index - 1);
    quicksort_decrescente(v, pivot_index + 1, end);
  }
}
void print_list(int *ptr_vector, ll size)
{
  for (ll i = 0; i < size; i++)
  {
    printf("%d\t", ptr_vector[i]);
  }

  printf("\n");
}

int main()
{

  int *vector = (int *)malloc(sizeof(int) * N);
  // a
  for (ll i = 0; i < N; i++)
  {
    vector[i] = i;
  }
  print_list(vector, N);
  quicksort_crescente(vector, 0, N - 1);
  print_list(vector, N);

  // b
  srand(10);
  for (ll i = 0; i < N; i++)
  {
    vector[i] = rand();
  }
  print_list(vector, N);
  quicksort_crescente(vector, 0, N - 1);
  print_list(vector, N);

  // c
  for (ll i = 0; i < N; i++)
  {
    vector[i] = i;
  }
  print_list(vector, N);
  quicksort_decrescente(vector, 0, N - 1);
  print_list(vector, N);
  free(vector);
  return 0;
}