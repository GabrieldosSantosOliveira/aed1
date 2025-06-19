#ifndef LIST_NUMERICA_H
#define LIST_NUMERICA_H
#include<stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct list *List;

List* create();
int size(List* ptr_list);
void add_end_list(List* ptr_list, int value);
void add_begin_list(List* ptr_list, int value);
void remove_begin_list(List* ptr_list);
void remove_end_list(List* ptr_list);
void remove_by_index_list(List* ptr_list,int index);
void add_by_index_list(List* ptr_list,int value,int index);
int find_by_index(List* ptr_list, int index);
bool is_empty_list(List* ptr_list);
void free_list(List* ptr_list);
void print_list(List* ptr_list);
void clean_list(List* ptr_list);
void bubble_sort_crescente(List* ptr_list);
void bubble_sort_decrescente(List* ptr_list);

void quick_sort_crescente(List *v);
void quick_sort_decrescente(List *v);

#endif