#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Animal{
    char nome[50];
    char tutor[50];
    char servico[50];
    char status[50];
    struct Animal proximo;
} Animal;
