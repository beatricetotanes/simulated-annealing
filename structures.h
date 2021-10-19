// Structures
#include <iostream>

typedef struct list{
    float num;
    struct list *next;
}list;

typedef struct trials_cycles{
    int trials;
    int cycles;
}trials_cycles;