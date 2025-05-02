#include <stdio.h>


void funcResultadoSoma() {
    float n1;
    float n2;
    float soma;

printf("Forneça o primeiro valor: ");
scanf("%f", &n1);

printf("Forneça o segundo valor: ");
scanf("%f", &n2);


soma = n1 + n2;

if(soma >= 10) {
    printf("A soma é maior ou igual a 10! O resultado é: %2.f", soma);
} else if(soma <= 10) {
    printf("A soma é menor que 10.");
}

}

