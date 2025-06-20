#include <stdio.h>
#include <stdlib.h>
#include "list_string.h"
#define N 1000000LL
typedef long long ll;
int main()
{

  List *list = create();
  List *list1 = create();

  FILE *file = fopen("nomes_aleatorios.txt", "r");

  if (file == NULL)
  {
    printf("ERRO ao abrir o arquivo\n");
    return -1;
  }

  ll i = 0;
  char *v = malloc(sizeof(char) * 200);
  while (i < N && fscanf(file, "%s", v) != EOF)
  {
    add_begin_list(list, v);
    add_begin_list(list1, v);
    i++;
  }
  free(v);
  bubble_sort_crescente(list);
  print_list(list);

  print_list(list1);
  bubble_sort_crescente(list1);
  print_list(list1);


  bubble_sort_decrescente(list);
  print_list(list);
  fclose(file);
  free_list(list1);
  free_list(list);

  return 0;
}