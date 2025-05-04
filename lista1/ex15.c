

#include <stdio.h>

void funcCalcularMediaAluno() {

    char aluno;
    int nota1;
    int nota2;
    int nota3;

    printf("Digite o nome do aluno: ");
    scanf("%c", &aluno);

    printf("Digite a primera nota do aluno: ");
    scanf("%d", &nota1);

    printf("Digite a segunda nota do aluno: ");
    scanf("%d", &nota2);

    printf("Digite a terceira nota do aluno: ");
    scanf("%d", &nota3);

    int media = nota1 + nota2 + nota3;

    if (media >= 7) {
        printf("Aluno aprovado!");
    } else if (media <= 5) {
        printf("Aluno está em recuperação");
    } else if (media >= 3) {
        printf("Aluno reprovado!");
    };
}

// int main() {
//     funcCalcularMediaAluno();
// }
