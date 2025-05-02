#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funcAge() {
    time_t ltime;
    struct tm *newtime;
    int anoDeNascimento;
    int idadeAtual;
    int idadeEm2050;

    // Get the current time
    time(&ltime);

    // Convert to local time
    newtime = localtime(&ltime);

    // tm_year is years since 1900, so add 1900 to get the current year
    int ano = newtime->tm_year + 1900;
    printf("Qual é seu ano de nascimento: ");
    scanf("%d", &anoDeNascimento);
    idadeAtual = ano - anoDeNascimento;
    idadeEm2050 = 2050 - anoDeNascimento;
    printf("Ano: %d\n", ano);
    printf("Idade Atual: %d\n", idadeAtual);
    printf("Idade em 2050: %d\n", idadeEm2050);
}
