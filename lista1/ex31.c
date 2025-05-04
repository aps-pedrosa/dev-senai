#include <stdio.h>

void funcOrdemDecrescente() {
    int numeros[3];


    for (int i = 0; i < 3; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);
    }


    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (numeros[i] < numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }

    // Saída
    printf("Ordem decrescente: %d, %d, %d\n", numeros[0], numeros[1], numeros[2]);
}

// int main() {
//     funcOrdemDecrescente();
//     return 0;
// }
