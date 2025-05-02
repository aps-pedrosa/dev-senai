#include <stdio.h>

// Função que avalia o aluno e imprime os resultados
void avaliarAluno() {
    char nome[100];
    float nota1, nota2, nota3, media;
    char *status;

    printf("Forneça o nome do aluno: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Forneça a primeira nota: ");
    scanf("%f", &nota1);

    printf("Forneça a segunda nota: ");
    scanf("%f", &nota2);

    printf("Forneça a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    if (media >= 7) {
        status = "Aprovado";
    } else {
        status = "Reprovado";
    }



    printf("\nNome do Aluno: %s", nome);
    printf("Média: %.2f\n", media);
    printf("Menção: %s\n", status);
}

