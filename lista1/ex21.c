

#include <stdio.h>

void ex21() {
    int numeroMaior;

    printf("Digite um numero: ");
    scanf("%d", &numeroMaior);

    if (numeroMaior >= 20) {
        printf("Metade do Numero: %d", numeroMaior / 2);
    } else if (numeroMaior < 20) {
        printf("Seu numero não é maior ou igual a 20!");
    }
}

//
// int main() {
//     funcNumeroMaiorQue20();
// }
