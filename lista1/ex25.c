#include <stdio.h>

void ex25() {
    int num1, num2, soma, resultado;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    soma = num1 + num2;

    if (soma > 20) {
        resultado = soma + 8;
    } else {
        resultado = soma - 5;
    }

    printf("Resultado: %d\n", resultado);
}

// int main() {
//     funcSomaComCondicao();
//     return 0;
// }
