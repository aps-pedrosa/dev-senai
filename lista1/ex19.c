// valor do salário mínimo é de R$1.518 em 2025
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ex19() {
    // Declaração de variáveis
    float salarioMinimo, qtdQuilowatts;
    float valorPorQuilowatt, valorTotal, valorComDesconto;
    
    // Configura o locale para português (acentos e vírgula como separador decimal)
    setlocale(LC_ALL, "Portuguese");
    
    // Limpa a tela
    system("clear || cls");
    
    // Entrada de dados
    printf("Digite o valor do salário mínimo: R$ ");
    scanf("%f", &salarioMinimo);
    
    printf("Digite a quantidade de quilowatts consumida: ");
    scanf("%f", &qtdQuilowatts);
    
    // Processamento
    // 100 quilowatts = 1/7 do salário mínimo
    // Logo, 1 quilowatt = (1/7 * salário mínimo) / 100
    valorPorQuilowatt = (salarioMinimo / 7.0) / 100.0;
    valorTotal = valorPorQuilowatt * qtdQuilowatts;
    valorComDesconto = valorTotal * 0.9; // 10% de desconto
    printf("a. Valor de cada quilowatt: R$ %.2f\n", valorPorQuilowatt);
    printf("b. Valor total a ser pago: R$ %.2f\n", valorTotal);
    printf("c. Valor com desconto de 10%%: R$ %.2f\n\n", valorComDesconto);
}
