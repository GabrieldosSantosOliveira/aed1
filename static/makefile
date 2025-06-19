entrada_numerica_bubble: main.c bubble_sort.o
	gcc entrada_numerica_bubble.c bubble_sort.o -o main

bubble_sort.o: bubble_sort.h bubble_sort.c
	gcc bubble_sort.c -c -o bubble_sort.o

quick.o: bubble_sort.h bubble_sort.c
	gcc -g quick_sort.c -c -o quick_sort.o

enq: main.c 
	gcc  entrada_textual.c -O2 -o main
