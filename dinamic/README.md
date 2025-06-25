
## Especificação

## 🚀 Como executar usando make

# 1 Entrada numerica usando bubble sort
```
make entrada_numerica_bubble_sort
```

# 2 Entrada numerica usando quick sort
```
make entrada_numerica_quick_sort
```
# 3 Entrada textual usando quick sort
```
make entrada_textual_quick_sort
```
# 4 Entrada textual usando bubble
```
make entrada_textual_bubble_sort
```
## 🚀 Como executar sem make

# 1 Entrada numerica usando bubble sort
```
gcc -Wall -O2 -c list_numerica.c -o list_numerica.o
gcc -Wall -O2 entrada_numerica_bubble_sort.c list_numerica.o -o main

```

# 2 Entrada numerica usando quick sort
```
gcc -Wall -O2 -c list_numerica.c -o list_numerica.o
gcc -Wall -O2 entrada_numerica_quick_sort.c list_numerica.o -o main

```
# 3 Entrada textual usando quick sort
```
gcc -Wall -O2 -c list_numerica.c -o list_numerica.o
gcc -Wall -O2 entrada_textual_quick_sort.c list_string.o -o main

```
# 4 Entrada textual usando bubble
```
gcc -Wall -O2 -c list_numerica.c -o list_numerica.o
gcc -Wall -O2 entrada_textual_bubble_sort.c list_string.o -o main

```