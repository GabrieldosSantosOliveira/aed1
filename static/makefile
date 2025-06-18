entrada_numerica_bubble: main.c bubble_sort.o
	gcc entrada_numerica.c bubble_sort.o -o main

bubble_sort.o: bubble_sort.h bubble_sort.c
	gcc bubble_sort.c -c -o bubble_sort.o

quick.o: bubble_sort.h bubble_sort.c
	gcc -g quick_sort.c -c -o quick_sort.o

enq: main.c quick.o
	gcc -g entrada_numerica_quick_sort.c quick_sort.o -o main
