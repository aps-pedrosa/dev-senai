#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#define UP_ARROW    65
#define DOWN_ARROW  66
#define ENTER_KEY   10

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

// Exibe o menu
void displayMenu(char *options[], int numOptions, int selected) {
    clearScreen();
    for (int i = 0; i < numOptions; i++) {
        if (i == selected) {
            printf(" > %s\n", options[i]);
        } else {
            printf("   %s\n", options[i]);
        }
    }
}

int main() {
    char *options[] = {"Option 1", "Option 2", "Option 3", "Exit"};
    int numOptions = sizeof(options) / sizeof(options[0]);
    int selected = 0;
    struct termios original;

    enableRawMode(&original); // Entra em modo raw

    while (1) {
        displayMenu(options, numOptions, selected);
        int key = getKey();

        if (key == UP_ARROW) {
            selected = (selected - 1 + numOptions) % numOptions;
        } else if (key == DOWN_ARROW) {
            selected = (selected + 1) % numOptions;
        } else if (key == ENTER_KEY) {
            clearScreen();
            if (selected == numOptions - 1) {
                printf("Exiting...\n");
                break;
            } else {
                printf("You selected: %s\n", options[selected]);
                printf("Press any key to return to the menu...\n");
                getKey();
            }
        }
    }

    disableRawMode(&original); // Restaura terminal

    return 0;
}
