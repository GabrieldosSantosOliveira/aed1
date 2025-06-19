#include <stdio.h>
#include <stdlib.h>
#define N 11
typedef long long ll;

ll pivo_rand(ll inicio, ll fim)
{
  return (rand() % (fim - inicio + 1)) + inicio;
}
int partition_crescente(int *v, ll begin, ll end)
{
  int index_p = pivo_rand(begin, end);
  int tmp;

  tmp = v[begin];
  v[begin] = v[index_p];
  v[index_p] = tmp;

  int pivot = v[begin];
  ll left = begin;
  ll right = end;
  while (left < right)
  {
    while (left <= end && v[left] <= pivot)
    {
      left++;
    }
    while (right > begin && v[right] > pivot)
    {
      right--;
    }
    if (left < right)
    {
      tmp = v[left];

      v[left] = v[right];
      v[right] = tmp;
    }
  }

  tmp = v[begin];
  v[begin] = v[right];
  v[right] = tmp;

  return right;
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
  int index_p = pivo_rand(begin, end);
  int tmp;

  tmp = v[begin];
  v[begin] = v[index_p];
  v[index_p] = tmp;

  int pivot = v[begin];
  ll left = begin + 1;
  ll right = end;
  while (left < right)
  {
    while (left <= end && v[left] >= pivot)
    {
      left++;
    }
    while (right > begin && v[right] < pivot)
    {
      right--;
    }
    if (left < right)
    {
      tmp = v[left];

      v[left] = v[right];
      v[right] = tmp;
    }
  }

  tmp = v[begin];
  v[begin] = v[right];
  v[right] = tmp;

  return right;
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

  int vector[N];
  srand(10);
  // a
  for (ll i = 0; i < N; i++)
  {
    vector[i] = i;
  }
  print_list(vector, N);
  quicksort_crescente(vector, 0, N - 1);
  print_list(vector, N);

  // b
  for (ll i = 0; i < N; i++)
  {
    vector[i] = rand() % 100;
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
  return 0;
}