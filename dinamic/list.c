#include "list.h"

#define REQUIRED_PTR_LIST(ptr_list)       \
  if (ptr_list == NULL)                   \
  {                                       \
    printf("ERRO PARAMETRO REQUERIDO\n"); \
    exit(EXIT_FAILURE);                   \
  }
struct list
{
  struct list *next;
  int value;
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
void add_end_list(List *ptr_list, int value)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  while (node->next != NULL)
  {
    node = node->next;
  }
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    exit(EXIT_FAILURE);
  tmp->next = NULL;
  tmp->value = value;
  node->next = tmp;
}
void add_begin_list(List *ptr_list, int value)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    exit(EXIT_FAILURE);

  tmp->next = node;
  tmp->value = value;
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
int find_by_index(List *ptr_list, int index)
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
void add_by_index_list(List *ptr_list, int value, int index)
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
  tmp->value = value;
  prev->next = tmp;
}

void print_list(List *ptr_list)
{
  REQUIRED_PTR_LIST(ptr_list);
  Node *node = *ptr_list;
  while (node != NULL)
  {
    printf("%d\t", node->value);
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
  int tmp = a->value;
  a->value = b->value;
  b->value = tmp;
}
Node *particiona(Node *head, Node *tail)
{
  Node *pivot = head;
  Node *left = head;
  Node *curr = head;
  while (curr != tail->next)
  {
    if (curr->value < pivot->value)
    {
      swap(curr, left->next);
      left = left->next;
    }
    curr = curr->next;
  }
  swap(pivot, left);
  return left;
}
void quicksort_imp(Node *head, Node *tail)
{

  if (head == tail || head == NULL || tail == NULL)
  {
    return;
  }

  Node *pivot = particiona(head, tail);
  quicksort_imp(head, pivot);
  quicksort_imp(pivot->next, tail);
}
Node *getTail(List *v)
{
  Node *node = *(v);
  while (node->next != NULL)
  {
    node = node->next;
  }
  return node;
}
void quick_sort(List *v)
{
  Node* tail = getTail(v);
  quicksort_imp(*(v), tail);
}