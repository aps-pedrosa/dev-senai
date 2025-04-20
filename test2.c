#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 100
#define NUM 6

typedef struct {
    char nome[LEN];
    char endereco[LEN];
    int cep;
    int cell;
} Elementos;

void tratarString(char *str) {
    // Converte a primeira letra em maiúscula e o resto em minúscula
    for (int j = 0; str[j]; j++) {
        if (j == 0)
            str[j] = toupper(str[j]);
        else
            str[j] = tolower(str[j]);
    }
}

