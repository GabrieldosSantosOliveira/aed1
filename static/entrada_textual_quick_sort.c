#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000LL

typedef long long ll;
ll pivo_rand(ll inicio, ll fim)
{
  return (rand() % (fim - inicio + 1)) + inicio;
}
int partition_crescente(char **v, ll begin, ll end)
{
  int index_p = pivo_rand(begin, end);
  char *tmp;

  tmp = v[begin];
  v[begin] = v[index_p];
  v[index_p] = tmp;

  char *pivot = v[begin];
  ll left = begin + 1;
  ll right = end;
  while (left < right)
  {
    while (left <= end && strcmp(v[left], pivot) <= 0)
    {
      left++;
    }
    while (right >= begin + 1 && strcmp(v[right], pivot) > 0)
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

void quicksort_crescente(char **v, ll begin, ll end)
{
  if (end > begin)
  {
    ll pivot_index = partition_crescente(v, begin, end);
    quicksort_crescente(v, begin, pivot_index - 1);
    quicksort_crescente(v, pivot_index + 1, end);
  }
}

int partition_decrescente(char **v, ll begin, ll end)
{
  int index_p = pivo_rand(begin, end);
  char *tmp;

  tmp = v[begin];
  v[begin] = v[index_p];
  v[index_p] = tmp;

  char *pivot = v[begin];
  ll left = begin + 1;
  ll right = end;
  while (left < right)
  {
    while (left <= end && strcmp(v[left], pivot) >= 0)
    {
      left++;
    }
    while (right >= begin + 1 && strcmp(v[right], pivot) < 0)
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

void quicksort_decrescente(char **v, ll begin, ll end)
{
  if (end > begin)
  {
    ll pivot_index = partition_decrescente(v, begin, end);
    quicksort_decrescente(v, begin, pivot_index - 1);
    quicksort_decrescente(v, pivot_index + 1, end);
  }
}
void print_list(char **ptr_vector, ll size)
{

  for (ll i = 0; i < 20; i++)
  {
    printf("%s\t", ptr_vector[i]);
  }
  printf("\n BAIXO ---------------\n");

  for (ll i = size - 1; i >= size - 20; i--)
  {
    printf("%s\t", ptr_vector[i]);
  }

  printf("\n");
}

int main()
{

  char **v1 = (char **)malloc(sizeof(char *) * N);
  char **v2 = (char **)malloc(sizeof(char *) * N);

  for (ll i = 0; i < N; i++)
  {
    v1[i] = (char *)malloc(sizeof(char) * 200);
    v2[i] = (char *)malloc(sizeof(char) * 200);
  }

  FILE *file = fopen("nomes_aleatorios.txt", "r");

  if (file == NULL)
  {
    printf("ERRO ao abrir o arquivo\n");
    return -1;
  }

  ll i = 0;
  while (i < N && fscanf(file, "%s", v1[i]) != EOF)
  {
    strcpy(v2[i], v1[i]);
    i++;
  }

  quicksort_crescente(v1, 0, N - 1);
  print_list(v1, N);

  print_list(v2, N);
  quicksort_decrescente(v2, 0, N - 1);
  print_list(v2, N);

  printf("C ------------\n");

  quicksort_decrescente(v1, 0, N - 1);
  print_list(v1, N);
  fclose(file);
  for (ll i = 0; i < N; i++)
  {
    free(v1[i]);
    free(v2[i]);
  }
  free(v1);
  free(v2);

  return 0;
}