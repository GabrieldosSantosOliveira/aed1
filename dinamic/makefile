enb:  entrada_numerica_bubble_sort.c list.o bubble_sort.o
	gcc -g entrada_numerica_bubble_sort.c bubble_sort.o list.o -o main

list.o: list.h list.c
	gcc -g list.c -c -o list.o

bubble_sort.o: bubble_sort.h bubble_sort.c
	gcc -g bubble_sort.c -c -o bubble_sort.o

quick.o: quick_sort.h quick_sort.c
	gcc -g quick_sort.c -c -o quick_sort.o

enq: entrada_numerica_quick_sort.c  list.o
	gcc -g entrada_numerica_quick_sort.c list.o  -o main
