CC=gcc
CARGS=-Wall -O2

entrada_numerica_bubble_sort: entrada_numerica_bubble_sort.c list_numerica.o
	$(CC) $(CARGS) entrada_numerica_bubble_sort.c list_numerica.o -o main
list_numerica.o: list_numerica.c list_numerica.h
	$(CC) $(CARGS) -c list_numerica.c -o list_numerica.o
entrada_numerica_quick_sort: entrada_numerica_quick_sort.c list_numerica.o
	$(CC) $(CARGS) entrada_numerica_quick_sort.c list_numerica.o -o main
entrada_textual_bubble_sort: entrada_textual_bubble_sort.c list_string.o
	$(CC) $(CARGS) entrada_textual_bubble_sort.c list_string.o -o main
entrada_textual_quick_sort: entrada_textual_quick_sort.c list_string.o
	$(CC) $(CARGS) entrada_textual_quick_sort.c list_string.o -o main
list_string.o: list_string.c list_string.h
	$(CC) $(CARGS) -c list_numerica.c -o list_numerica.o