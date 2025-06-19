CC=gcc
ARGS=-Wall -g

enb:  entrada_numerica_bubble_sort.c list.o bubble_sort.o
	$(CC) $(ARGS) entrada_numerica_bubble_sort.c bubble_sort.o list.o -o main

list.o: list.h list.c
	$(CC) $(ARGS) list.c -c -o list.o

bubble_sort.o: bubble_sort.h bubble_sort.c
	$(CC) $(ARGS) bubble_sort.c -c -o bubble_sort.o

quick.o: quick_sort.h quick_sort.c
	$(CC) $(ARGS) quick_sort.c -c -o quick_sort.o

list_string.o: list_string.h list_string.c
	$(CC) $(ARGS) list_string.c -c -o list_string.o

enq: entrada_textual_quick_sort.c  list_string.o
	$(CC) $(ARGS) entrada_textual_quick_sort.c list_string.o  -o main
