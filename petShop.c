#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Animal
{
    char nome[50];
    char tutor[50];
    char servico[50];
    char status[50];
    struct Animal *proximo;
} Animal;

Animal *inicio = NULL;

Animal *alocarMemoriaPonteiro()
{
    Animal *ponteiro = (Animal *)malloc(sizeof(Animal));

    if (!ponteiro)
    {
        printf("Erro ao alocar novo espaço de memória.\n");
        return NULL;
    }
    return ponteiro;
}

void entradaDadosString(char *buffer, size_t tamanho)
{
    if (fgets(buffer, tamanho, stdin))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

char *menuServico()
{
    int opcaoServico = 0;
    static char servicoEscolhido[50];

    do
    {
        printf("\nQual o serviço desejado do Pet Shop Mundo Cão?\n");
        printf("Escolha uma opção:\n");
        printf("1 - Banho.\n");
        printf("2 - Tosa.\n");
        printf("3 - Ambos (banho e tosa).\n");
        printf("Opção: ");
        scanf("%d", &opcaoServico);

        switch (opcaoServico)
        {
        case 1:
            strcpy(servicoEscolhido, "banho");
            printf("Serviço definido como 'banho'.\n");
            opcaoServico = 9;
            break;

        case 2:
            strcpy(servicoEscolhido, "tosa");
            printf("Serviço definido como 'tosa'.\n");
            opcaoServico = 9;
            break;

        case 3:
            strcpy(servicoEscolhido, "ambos");
            printf("Serviço definido como 'ambos'.\n");
            opcaoServico = 9;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcaoServico != 9);

    return servicoEscolhido;
}

char *statusServico()
{
    int opcaoStatusServico = 0;
    static char statusEscolhido[50];

    do
    {
        printf("\nQual o status do serviço do seu pet?\n");
        printf("Escolha uma opção:\n");
        printf("1 - Aguardando.\n");
        printf("2 - Em andamento.\n");
        printf("3 - Finalizado.\n");
        printf("Opção: ");
        scanf("%d", &opcaoStatusServico);

        switch (opcaoStatusServico)
        {
        case 1:
            strcpy(statusEscolhido, "aguardando");
            printf("Serviço definido como 'aguardando'.\n");
            opcaoStatusServico = 9;
            break;

        case 2:
            strcpy(statusEscolhido, "em andamento");
            printf("Serviço definido como 'em andamento'.\n");
            opcaoStatusServico = 9;
            break;

        case 3:
            strcpy(statusEscolhido, "finalizado");
            printf("Serviço definido como 'finalizado'.\n");
            opcaoStatusServico = 9;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcaoStatusServico != 9);

    return statusEscolhido;
}

void cadastrarAnimal()
{
    Animal *novoAnimal = alocarMemoriaPonteiro();
    Animal *auxiliar = inicio;

    if (novoAnimal == NULL)
        return;

    printf("Digite o nome do animal: ");
    entradaDadosString(novoAnimal->nome, sizeof(novoAnimal->nome));

    printf("Digite o nome do tutor: ");
    entradaDadosString(novoAnimal->tutor, sizeof(novoAnimal->tutor));

    printf("Digite o nome do serviço solicitado: ");
    strcpy(novoAnimal->servico, menuServico());

    printf("Escolha o status do serviço: ");
    strcpy(novoAnimal->status, statusServico());

    if (auxiliar == NULL)
    {
        auxiliar = novoAnimal;
        novoAnimal->proximo = NULL;
        return
    }

    while (auxiliar->proximo != NULL)
    {
        auxiliar = auxiliar->proximo;
    }
    auxiliar->proximo = novoAnimal;
    novoAnimal->proximo = NULL;
}

int main()
{
    int opcao;
    do
    {
        printf("\nBem-vindo ao Pet Shop Mundo Cão!\n");
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar animal.\n");
        printf("9 - Sair.\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarAnimal();
            break;

        case 9:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 9);

    return 0;
}
