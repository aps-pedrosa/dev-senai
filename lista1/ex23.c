

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// @alinatalent thx for the fix
void stringLower(char *str) {
    for (; *str; ++str) {
        *str = tolower((unsigned char)*str);
    }
}

void funcCapitalDoBrasil() {
    char resposta[100];

    printf("Qual é a capital do Brasil: ");
    scanf("%s", resposta);

    stringLower(resposta);

    if (strcmp(resposta, "brasilia") == 0 || strcmp(resposta, "brasília") == 0)  {
        printf("Resposta certa!");
    } else {
        printf("Resposta incorreta.");
    };
};


// int main() {
//     funcCapitalDoBrasil();
// }