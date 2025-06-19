#include "list_string.h"
#include <string.h>
typedef long long ll;
#define REQUIRED_PTR_LIST(ptr_list)       \
  if (ptr_list == NULL)                   \
  {                                       \
    printf("ERRO PARAMETRO REQUERIDO\n"); \
    exit(EXIT_FAILURE);                   \
  }
struct list
{
  struct list *next;
  char value[200];
};
typedef struct list Node;
List *create()
{
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL)
  {
    exit(EXIT_FAILURE);
  }
  *(list) = NULL;
  return list;
}
int size(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  int i = 0;
  while (node != NULL)
  {
    node = node->next;
    i++;
  }
  return i;
}
void add_end_list(List *ptr_list, char value[200])
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  if (size(ptr_list) == 0)
  {
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL)
      exit(EXIT_FAILURE);
    tmp->next = NULL;
    strcpy(tmp->value, value);
    *(ptr_list) = tmp;
    return;
  }
  while (node->next != NULL)
  {
    node = node->next;
  }
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    exit(EXIT_FAILURE);
  tmp->next = NULL;
  strcpy(tmp->value, value);
  node->next = tmp;
}
void add_begin_list(List *ptr_list, char value[200])
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    exit(EXIT_FAILURE);

  tmp->next = node;
  strcpy(tmp->value, value);
  *(ptr_list) = tmp;
}
void remove_begin_list(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  *(ptr_list) = node->next;
  free(node);
}
void remove_end_list(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  Node *prev = NULL;
  while (node->next != NULL)
  {
    prev = node;
    node = node->next;
  }
  prev->next = NULL;
  free(node);
}
char *find_by_index(List *ptr_list, int index)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  int i = 0;
  while (node != NULL)
  {
    if (i == index)
    {
      return node->value;
    }
    node = node->next;
    i++;
  }
  exit(EXIT_FAILURE);
}
bool is_empty_list(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  if (size(ptr_list) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void free_list(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  Node *tmp;
  while (node != NULL)
  {
    tmp = node;
    node = node->next;
    free(tmp);
  }
  free(ptr_list);
}
void remove_by_index_list(List *ptr_list, int index)
{
  REQUIRED_PTR_LIST(ptr_list);
  if (index == 0)
  {
    return remove_begin_list(ptr_list);
  }
  if (index == size(ptr_list) - 1)
  {
    return remove_end_list(ptr_list);
  }
  Node *node = *ptr_list;
  Node *prev = NULL;
  int i = 0;
  while (node != NULL)
  {
    if (i == index)
    {
      break;
    }
    prev = node;
    node = node->next;
    i++;
  }
  prev->next = node->next;
  free(node);
}
void add_by_index_list(List *ptr_list, char value[200], int index)
{
  REQUIRED_PTR_LIST(ptr_list);
  if (index == 0)
  {
    return add_begin_list(ptr_list, value);
  }
  if (index == size(ptr_list) - 1)
  {
    return add_end_list(ptr_list, value);
  }

  Node *node = *ptr_list;
  Node *prev = NULL;
  int i = 0;
  while (node != NULL)
  {
    if (i == index)
    {
      break;
    }
    prev = node;
    node = node->next;
    i++;
  }
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    exit(EXIT_FAILURE);
  tmp->next = node;
  strcpy(tmp->value, value);
  prev->next = tmp;
}

void print_list(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  while (node != NULL)
  {
    printf("%s\t", node->value);
    node = node->next;
  }
  printf("\n");
}
void clean_list(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  Node *tmp;
  while (node != NULL)
  {
    tmp = node;
    node = node->next;
    free(tmp);
  }
  *(ptr_list) = NULL;
}

void swap(Node *a, Node *b)
{
  char tmp[200];
  strcpy(tmp, a->value);
  strcpy(a->value, b->value);
  strcpy(b->value, tmp);
}

Node *getTail(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *(ptr_list);
  while (node->next != NULL)
  {
    node = node->next;
  }
  return node;
}

void bubble_sort_crescente(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  ll fim = size(ptr_list) - 1;
  while (true)
  {
    bool flag = true;
    ll i = 0;
    Node *node = *(ptr_list);
    Node *next = node->next;
    while (i < fim)
    {

      if (strcmp(node->value, next->value) > 0)
      {
        swap(node, next);
        flag = false;
      }
      node = node->next;
      next = node->next;
      i++;
    }
    if (flag)
    {
      break;
    }
    fim = fim - 1;
  }
}
void bubble_sort_decrescente(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  ll fim = size(ptr_list) - 1;
  while (true)
  {
    bool flag = true;
    ll i = 0;
    Node *node = *(ptr_list);
    Node *next = node->next;
    while (i < fim)
    {

      if (strcmp(node->value, next->value) < 0)
      {
        swap(node, next);
        flag = false;
      }
      node = node->next;
      next = node->next;
      i++;
    }
    if (flag)
    {
      break;
    }
    fim = fim - 1;
  }
}
Node *get_random_node(Node *head, Node *tail)
{
  ll n = 0;
  Node *tmp = head;
  while (tmp != NULL && tmp != tail)
  {
    n++;
    tmp = tmp->next;
  }
  if (n == 0)
  {
    return head;
  }
  ll index = rand() % n;
  tmp = head;
  for (int i = 0; i < index; i++)
  {
    tmp = tmp->next;
  }
  return tmp;
}
Node *particiona_crescente(Node *head, Node *tail)
{
  Node *t = get_random_node(head, tail);
  swap(head, t);
  Node *pivot = head;
  Node *left = head;
  Node *curr = head;
  while (curr != tail->next)
  {
    if (strcmp(curr->value, pivot->value) < 0)
    {
      swap(curr, left->next);
      left = left->next;
    }
    curr = curr->next;
  }
  swap(pivot, left);
  return left;
}
void quicksort_imp_crescente(Node *head, Node *tail)
{

  if (head == tail || head == NULL || tail == NULL)
  {
    return;
  }

  Node *pivot = particiona_crescente(head, tail);
  quicksort_imp_crescente(head, pivot);
  quicksort_imp_crescente(pivot->next, tail);
}

void quick_sort_crescente(List *v)
{
  REQUIRED_PTR_LIST(v);
  Node *tail = getTail(v);
  quicksort_imp_crescente(*(v), tail);
}
Node *particiona_decrescente(Node *head, Node *tail)
{
  Node *t = get_random_node(head, tail);
  swap(head, t);
  Node *pivot = head;
  Node *left = head;
  Node *curr = head;
  while (curr != tail->next)
  {
    if (strcmp(curr->value, pivot->value) > 0)
    {
      swap(curr, left->next);
      left = left->next;
    }
    curr = curr->next;
  }
  swap(pivot, left);
  return left;
}
void quicksort_imp_decrescente(Node *head, Node *tail)
{

  if (head == tail || head == NULL || tail == NULL)
  {
    return;
  }

  Node *pivot = particiona_decrescente(head, tail);
  quicksort_imp_decrescente(head, pivot);
  quicksort_imp_decrescente(pivot->next, tail);
}

void quick_sort_decrescente(List *v)
{
  REQUIRED_PTR_LIST(v);
  Node *tail = getTail(v);
  quicksort_imp_decrescente(*(v), tail);
}