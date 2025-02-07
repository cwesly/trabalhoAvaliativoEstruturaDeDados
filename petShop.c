#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Animal
{
    char nome[50];
    char tutor[50];
    char servico[50];
    char status[50];
    struct Animal proximo;
} Animal;

int main()
{
    int opcao = 1;
    do
    {
        printf("\nBem-vindo ao Pet Shop Mundo Cão!\n");
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar animal.\n");
        printf("Opção: ");
        scanf("%d", opcao);

        switch (opcao)
        {
        case 1:
            cadastrarAnimal();
            break;

        case 9:
            printf("Saindo...");
            break;

        default:
            printf("Opção inválida!");
            break;
        }
    } while (opcao != 9);
}