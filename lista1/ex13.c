#include <stdio.h>
#include <stdlib.h>

void ex13()
{
    char nome[50];
    float salario;
    float vendas;
    float salariofinal;

    printf("Qual é o nome do vendedor: ");
    scanf("%s", nome);

    printf("Qual é o salário do vendedor: ");
    scanf("%f", &salario);

    printf("Qual foi o total de vendas efetuadas este mês: ");
    scanf("%f", &vendas);

    salariofinal = salario + (vendas * 0.15); // Exemplo: 15% de comissão

    printf("\nVendedor: %s", nome);
    printf("\nSalário Fixo: R$ %.2f", salario);
    printf("\nSalário Final de %s: R$ %.2f", nome, salariofinal);
}

// int main() {
// funcVendedor();
// }
