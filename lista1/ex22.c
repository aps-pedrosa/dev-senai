#include <stdio.h>

void verificarSinal() {
    float numero;

    printf("Digite um número: ");
    scanf("%f", &numero);

    if (numero > 0) {
        printf("O número é positivo.\n");
    } else if (numero < 0) {
        printf("O número é negativo.\n");
    } else {
        printf("O número é nulo (zero).\n");
    }
}

int main() {
    verificarSinal();
    return 0;
}
