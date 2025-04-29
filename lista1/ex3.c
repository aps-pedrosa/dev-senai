#include <stdio.h>

int main() {

    int n1;
    int n2;
    int n3;
    int n4;

    printf("Digite o primeiro número: ");
    scanf("%d", &n1);

    printf("Digite o segundo número: ");
    scanf("%d", &n2);

    printf("Digite o terceiro número: ");
    scanf("%d", &n3);

    printf("Digite o quarto número: ");
    scanf("%d", &n4);

    int soma = n1 + n2 + n3 + n4;

    printf("A soma final dos 4 números é de: " "%d", soma);


}
