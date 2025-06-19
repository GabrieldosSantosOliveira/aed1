#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 1000000LL

typedef long long ll;
void bubble_sort_crescente(char **ptr_vector, ll size)
{
  ll fim = size - 1;
  ll i = 0;
  char *tmp;
  while (i < size)
  {
    bool flag = true;

    for (ll i = 0; i < fim; i++)
    {
      if (strcmp(ptr_vector[i], ptr_vector[i + 1]) > 0)
      {
        tmp = ptr_vector[i];
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
void bubble_sort_decrescente(char **ptr_vector, ll size)
{
  ll fim = size - 1;
  ll i = 0;
  char *tmp;

  while (i < size)
  {
    bool flag = true;

    for (ll i = 0; i < fim; i++)
    {
      if (strcmp(ptr_vector[i], ptr_vector[i + 1]) > 0)
      {
        tmp = ptr_vector[i];
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
  bubble_sort_crescente(v1, N);
  print_list(v1, N);

  print_list(v2, N);
  bubble_sort_decrescente(v2, N);
  print_list(v2, N);

  printf("C ------------\n");

  bubble_sort_decrescente(v1, N);
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