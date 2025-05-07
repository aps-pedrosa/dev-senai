#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ex1.c"
#include "ex2.c"
#include "ex3.c"
#include "ex4.c"
#include "ex5.c"
#include "ex6.c"
#include "ex7.c"
#include "ex8.c"
#include "ex9.c"
#include "ex10.c"
#include "ex11.c"
#include "ex12.c"
#include "ex13.c"
#include "ex14.c"
#include "ex15.c"
#include "ex16.c"
#include "ex17.c"
#include "ex18.c"
#include "ex19.c"
#include "ex20.c"
#include "ex21.c"
#include "ex22.c"
#include "ex23.c"
#include "ex24.c"
#include "ex25.c"
#include "ex26.c"
#include "ex27.c"
#include "ex28.c"
#include "ex29.c"
#include "ex30.c"
#include "ex31.c"
#include "ex32.c"
#include "ex33.c"
#include "ex34.c"
#include "ex35.c"
#include "ex36.c"
#include "ex37.c"
#include "ex38.c"
#include "ex39.c"
#include "ex40.c"
#include "ex41.c"

#define UP_ARROW    65
#define DOWN_ARROW  66
#define ENTER_KEY   10
#define PAGE_SIZE   10  // Número de opções visíveis por página

// Habilita modo raw para capturar teclas sem esperar Enter
void enableRawMode(struct termios *original) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, original);
    raw = *original;
    raw.c_lflag &= ~(ICANON | ECHO); // Desativa modo canônico e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

// Restaura modo de terminal padrão
void disableRawMode(struct termios *original) {
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

// Captura tecla pressionada
int getKey() {
    int c;
    c = getchar();
    if (c == 27) { // ESC
        if (getchar() == 91) { // [
            c = getchar(); // Código da seta
        }
    }
    return c;
}

// Limpa tela (Linux/Unix)
void clearScreen() {
    printf("\033[2J\033[H");
}

// Desenha borda superior
void drawTopBorder(int width) {
    printf("┌");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┐\n");
}

// Desenha borda inferior
void drawBottomBorder(int width) {
    printf("└");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┘\n");
}

// Exibe o menu com paginação
void displayMenu(char *options[], int numOptions, int selected, int startIdx) {
    clearScreen();
    int width = 80; // Largura do menu
    
    // Desenha cabeçalho
    drawTopBorder(width);
    printf("│%*s%*s│\n", width/2 + 10, "EXERCÍCIOS SENAI", width/2 - 10, "");
    printf("├");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┤\n");
    
    // Exibe as opções da página atual
    int endIdx = startIdx + PAGE_SIZE;
    if (endIdx > numOptions) endIdx = numOptions;
    
    for (int i = startIdx; i < endIdx; i++) {
        if (i == selected) {
            printf("│ \033[1;32m→ %2d. %s\033[0m", i + 1, options[i]);
            int padding = width - strlen(options[i]) - 8;
            for (int j = 0; j < padding; j++) printf(" ");
            printf("│\n");
        } else {
            printf("│   %2d. %s", i + 1, options[i]);
            int padding = width - strlen(options[i]) - 8;
            for (int j = 0; j < padding; j++) printf(" ");
            printf("│\n");
        }
    }
    
    // Preenche o espaço restante se necessário
    for (int i = endIdx; i < startIdx + PAGE_SIZE; i++) {
        printf("│%*s│\n", width - 2, "");
    }
    
    // Exibe informações de navegação
    printf("├");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┤\n");
    
    printf("│ Página %d/%d", (selected / PAGE_SIZE) + 1, (numOptions / PAGE_SIZE) + 1);
    int pagePadding = width - 20;
    for (int i = 0; i < pagePadding; i++) printf(" ");
    printf("│\n");
    
    printf("│ Use as setas ↑↓ para navegar e ENTER para selecionar");
    int navPadding = width - 52;
    for (int i = 0; i < navPadding; i++) printf(" ");
    printf("│\n");
    
    drawBottomBorder(width);
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura para caracteres em português
    
    // Funções externas dos arquivos incluídos
    // Não é necessário declarar protótipos aqui, pois as funções
    // já são incluídas pelos arquivos .c que contêm as implementações
    
    // Títulos dos exercícios
    char *options[] = {
        "Multiplicação de dois números",
        "Divisão de dois números",
        "Soma de quatro números inteiros",
        "Média aritmética de três notas",
        "Aumento de salário de 25%",
        "Área de um triângulo",
        "Nome e idade do usuário",
        "Um número elevado ao outro",
        "Cálculo de idade",
        "Cálculo de peso",
        "Número par ou ímpar",
        "Consumo médio de um automóvel",
        "Salário de vendedor com comissão",
        "Média e aprovação de aluno",
        "Média e menção de aluno",
        "Terça parte de um número",
        "Cálculo de logaritmo",
        "Quadrado e raiz quadrada",
        "Cálculo de consumo de energia",
        "Perímetro e área de um círculo",
        "Metade se maior que 20",
        "Número positivo, negativo ou nulo",
        "Capital do Brasil",
        "Adição maior que 10",
        "Adição com condicionais",
        "Divisibilidade por 3 e por 7",
        "Divisibilidade por 10, 5 e 2",
        "Número entre 20 e 90",
        "Sigla do estado",
        "Maior número entre três",
        "Ordem decrescente de três números",
        "Categorias de natação",
        "Equação do segundo grau",
        "Sistema de biblioteca",
        "Quadrado de cinco números",
        "Números pares de 1 a 10",
        "Números de 1 a 100",
        "Números de 100 a 1",
        "Múltiplos de 5 de 1 a 500",
        "Números de 120 a 300",
        "Números de 1 a 100 e sua soma",
        "Sair"
    };
    
    int numOptions = sizeof(options) / sizeof(options[0]);
    int selected = 0;
    struct termios original;
    
    enableRawMode(&original); // Entra em modo raw
    
    while (1) {
        // Calcula o índice de início da página atual
        int startIdx = (selected / PAGE_SIZE) * PAGE_SIZE;
        
        displayMenu(options, numOptions, selected, startIdx);
        int key = getKey();
        
        if (key == UP_ARROW) {
            selected = (selected - 1 + numOptions) % numOptions;
        } else if (key == DOWN_ARROW) {
            selected = (selected + 1) % numOptions;
        } else if (key == ENTER_KEY) {
            clearScreen();
            if (selected == numOptions - 1) {
                printf("\n\n   Saindo do programa...\n\n");
                break;
            } else {
                // Chamadas diretas às funções dos arquivos incluídos
                switch (selected) {
                    case 0: ex1(); break;
                    case 1: ex2(); break;
                    case 2: ex3(); break;
                    case 3: ex4(); break;
                    case 4: ex5(); break;
                    case 5: ex6(); break;
                    case 6: ex7(); break;
                    case 7: ex8(); break;
                    case 8: ex9(); break;
                    case 9: ex10(); break;
                    case 10: ex11(); break;
                    case 11: ex12(); break;
                    case 12: ex13(); break;
                    case 13: ex14(); break;
                    case 14: ex15(); break;
                    case 15: ex16(); break;
                    case 16: ex17(); break;
                    case 17: ex18(); break;
                    case 18: ex19(); break;
                    case 19: ex20(); break;
                    case 20: ex21(); break;
                    case 21: ex22(); break;
                    case 22: ex23(); break;
                    case 23: ex24(); break;
                    case 24: ex25(); break;
                    case 25: ex26(); break;
                    case 26: ex27(); break;
                    case 27: ex28(); break;
                    case 28: ex29(); break;
                    case 29: ex30(); break;
                    case 30: ex31(); break;
                    case 31: ex32(); break;
                    case 32: ex33(); break;
                    case 33: ex34(); break;
                    case 34: ex35(); break;
                    case 35: ex36(); break;
                    case 36: ex37(); break;
                    case 37: ex38(); break;
                    case 38: ex39(); break;
                    case 39: ex40(); break;
                    case 40: ex41(); break;
                }
            }
        }
    }
    
    disableRawMode(&original); // Restaura terminal
    return 0;
}
