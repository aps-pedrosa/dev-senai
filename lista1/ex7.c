#include <stdio.h>

void funcCadastrar() {
    char nome[100];
    int idade;

    printf("Digite o nome do usuário: ");
    scanf("%s", nome);

    printf("Digite a idade do usuário: ");
    scanf("%d", &idade);

    printf("\nNome do usuário: %s", nome);
    printf("\nIdade do usuario: %d\n", idade);
}

