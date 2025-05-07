#include <stdio.h>
#include <math.h>
#include "ex1.c"
#include "ex2.c"
#include "ex3.c"
#include "ex4.c"
#include "ex5.c"
#include "ex6.c"
#include "ex8.c"
#include "ex9.c"
#include "ex10.c"
#include "ex11.c"
#include "ex12.c"
#include "ex14.c"
#include "ex16.c"
#include "ex18.c"
#include "ex20.c"
#include "ex22.c"
#include "ex24.c"
#include "ex26.c"
#include "ex28.c"
#include "ex30.c"
#include "ex32.c"
#include "ex34.c"
#include "ex36.c"
#include "ex38.c"
#include "ex40.c"
#include "ex41.c"
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define UP_ARROW    65
#define DOWN_ARROW  66
#define ENTER_KEY   10
#define PAGE_SIZE   10  // Número de opções visíveis por página

// Protótipos das funções dos exercícios
void ex01(); void ex02(); void ex03(); void ex04(); void ex05();
void ex06(); void ex07(); void ex08(); void ex09(); void ex10();
void ex11(); void ex12(); void ex13(); void ex14(); void ex15();
void ex16(); void ex17(); void ex18(); void ex19(); void ex20();
void ex21(); void ex22(); void ex23(); void ex24(); void ex25();
void ex26(); void ex27(); void ex28(); void ex29(); void ex30();
void ex31(); void ex32(); void ex33(); void ex34(); void ex35();
void ex36(); void ex37(); void ex38(); void ex39(); void ex40();
void ex41();

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

// Função para exibir tela de exercício com título
void showExerciseScreen(const char* title) {
    clearScreen();
    int width = 80;
    
    drawTopBorder(width);
    
    // Centraliza o título
    int titleLen = strlen(title);
    int padding = (width - 2 - titleLen) / 2;
    printf("│");
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s", title);
    for (int i = 0; i < width - 2 - padding - titleLen; i++) printf(" ");
    printf("│\n");
    
    printf("├");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┤\n");
    
    // Corpo do exercício
    for (int i = 0; i < 10; i++) {
        printf("│%*s│\n", width - 2, "");
    }
    
    printf("├");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┤\n");
    printf("│ Pressione qualquer tecla para voltar ao menu%*s│\n", width - 44, "");
    
    drawBottomBorder(width);
    
    getKey(); // Aguarda uma tecla para retornar
}

// Implementações das funções de exercícios
void ex01() {
    showExerciseScreen("Exercício 1 - Multiplicação de dois números");
}

void ex02() {
    showExerciseScreen("Exercício 2 - Divisão de dois números");
}

void ex03() {
    showExerciseScreen("Exercício 3 - Soma de quatro números inteiros");
}

void ex04() {
    showExerciseScreen("Exercício 4 - Média aritmética de três notas");
}

void ex05() {
    showExerciseScreen("Exercício 5 - Aumento de salário de 25%");
}

void ex06() {
    showExerciseScreen("Exercício 6 - Área de um triângulo");
}

void ex07() {
    showExerciseScreen("Exercício 7 - Nome e idade do usuário");
}

void ex08() {
    showExerciseScreen("Exercício 8 - Um número elevado ao outro");
}

void ex09() {
    showExerciseScreen("Exercício 9 - Cálculo de idade");
}

void ex10() {
    showExerciseScreen("Exercício 10 - Cálculo de peso");
}

void ex11() {
    showExerciseScreen("Exercício 11 - Número par ou ímpar");
}

void ex12() {
    showExerciseScreen("Exercício 12 - Consumo médio de um automóvel");
}

void ex13() {
    showExerciseScreen("Exercício 13 - Salário de vendedor com comissão");
}

void ex14() {
    showExerciseScreen("Exercício 14 - Média e aprovação de aluno");
}

void ex15() {
    showExerciseScreen("Exercício 15 - Média e menção de aluno");
}

void ex16() {
    showExerciseScreen("Exercício 16 - Terça parte de um número");
}

void ex17() {
    showExerciseScreen("Exercício 17 - Cálculo de logaritmo");
}

void ex18() {
    showExerciseScreen("Exercício 18 - Quadrado e raiz quadrada");
}

void ex19() {
    showExerciseScreen("Exercício 19 - Cálculo de consumo de energia");
}

void ex20() {
    showExerciseScreen("Exercício 20 - Perímetro e área de um círculo");
}

void ex21() {
    showExerciseScreen("Exercício 21 - Metade se maior que 20");
}

void ex22() {
    showExerciseScreen("Exercício 22 - Número positivo, negativo ou nulo");
}

void ex23() {
    showExerciseScreen("Exercício 23 - Capital do Brasil");
}

void ex24() {
    showExerciseScreen("Exercício 24 - Adição maior que 10");
}

void ex25() {
    showExerciseScreen("Exercício 25 - Adição com condicionais");
}

void ex26() {
    showExerciseScreen("Exercício 26 - Divisibilidade por 3 e por 7");
}

void ex27() {
    showExerciseScreen("Exercício 27 - Divisibilidade por 10, 5 e 2");
}

void ex28() {
    showExerciseScreen("Exercício 28 - Número entre 20 e 90");
}

void ex29() {
    showExerciseScreen("Exercício 29 - Sigla do estado");
}

void ex30() {
    showExerciseScreen("Exercício 30 - Maior número entre três");
}

void ex31() {
    showExerciseScreen("Exercício 31 - Ordem decrescente de três números");
}

void ex32() {
    showExerciseScreen("Exercício 32 - Categorias de natação");
}

void ex33() {
    showExerciseScreen("Exercício 33 - Equação do segundo grau");
}

void ex34() {
    showExerciseScreen("Exercício 34 - Sistema de biblioteca");
}

void ex35() {
    showExerciseScreen("Exercício 35 - Quadrado de cinco números");
}

void ex36() {
    showExerciseScreen("Exercício 36 - Números pares de 1 a 10");
}

void ex37() {
    showExerciseScreen("Exercício 37 - Números de 1 a 100");
}

void ex38() {
    showExerciseScreen("Exercício 38 - Números de 100 a 1");
}

void ex39() {
    showExerciseScreen("Exercício 39 - Múltiplos de 5 de 1 a 500");
}

void ex40() {
    showExerciseScreen("Exercício 40 - Números de 120 a 300");
}

void ex41() {
    showExerciseScreen("Exercício 41 - Números de 1 a 100 e sua soma");
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura para caracteres em português
    
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
    
    // Array de ponteiros para as funções dos exercícios
    void (*exerciseFunctions[41])() = {
        ex01, ex02, ex03, ex04, ex05, ex06, ex07, ex08, ex09, ex10,
        ex11, ex12, ex13, ex14, ex15, ex16, ex17, ex18, ex19, ex20,
        ex21, ex22, ex23, ex24, ex25, ex26, ex27, ex28, ex29, ex30,
        ex31, ex32, ex33, ex34, ex35, ex36, ex37, ex38, ex39, ex40,
        ex41
    };
    
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
                // Chama a função do exercício selecionado
                (*exerciseFunctions[selected])();
            }
        }
    }
    
    disableRawMode(&original); // Restaura terminal
    return 0;
}
