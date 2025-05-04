#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stringUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void funcEstadoOrigem() {
    char estado[3]; // 2 letras + \0

    printf("Digite a sigla do seu estado (ex: RJ, SP, MG): ");
    scanf("%2s", estado); // lê até 2 caracteres

    stringUpper(estado); // padroniza para maiúsculas

    if (strcmp(estado, "RJ") == 0) {
        printf("Carioca\n");
    } else if (strcmp(estado, "SP") == 0) {
        printf("Paulista\n");
    } else if (strcmp(estado, "MG") == 0) {
        printf("Mineiro\n");
    } else {
        printf("Outros estados\n");
    }
}

// int main() {
//     funcEstadoOrigem();
//     return 0;
// }
