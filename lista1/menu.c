#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#define MAX_OPTIONS 10
#define MAX_OPTION_LEN 50

// Structure to hold menu information
typedef struct {
    char options[MAX_OPTIONS][MAX_OPTION_LEN];
    int count;
    int selected;
} Menu;

// Function prototypes
void initMenu(Menu *menu);
void addOption(Menu *menu, const char *option);
void displayMenu(const Menu *menu);
int handleInput(Menu *menu);
void clearScreen();

#ifdef _WIN32
// Windows specific functions
int kbhit() {
    return _kbhit();
}

int getch() {
    return _getch();
}

void clearScreen() {
    system("cls");
}

#else
// Linux specific functions
static struct termios old, current;

// Initialize new terminal i/o settings
void initTermios() {
    tcgetattr(0, &old);          // Save old terminal settings
    current = old;               // Copy old settings to current
    current.c_lflag &= ~ICANON;  // Disable buffered i/o
    current.c_lflag &= ~ECHO;    // Disable echo
    tcsetattr(0, TCSANOW, &current); // Apply new settings
}

// Restore old terminal i/o settings
void resetTermios() {
    tcsetattr(0, TCSANOW, &old);
}

// Read 1 character - no echo, no wait
int getch() {
    int ch;
    initTermios();
    ch = getchar();
    resetTermios();
    return ch;
}

// Check if keyboard has been hit
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
}

void clearScreen() {
    printf("\033[2J\033[H"); // ANSI escape sequence to clear screen and move cursor to home
}
#endif

// Initialize the menu
void initMenu(Menu *menu) {
    menu->count = 0;
    menu->selected = 0;
}

// Add an option to the menu
void addOption(Menu *menu, const char *option) {
    if (menu->count < MAX_OPTIONS) {
        strncpy(menu->options[menu->count], option, MAX_OPTION_LEN - 1);
        menu->options[menu->count][MAX_OPTION_LEN - 1] = '\0';
        menu->count++;
    }
}

// Display the menu with current selection highlighted
void displayMenu(const Menu *menu) {
    clearScreen();
    printf("=== Menu ===\n");
    for (int i = 0; i < menu->count; i++) {
        if (i == menu->selected) {
            printf("> %s <\n", menu->options[i]);
        } else {
            printf("  %s\n", menu->options[i]);
        }
    }
    printf("\nUse arrow keys or 'j'/'k' to navigate, Enter to select, 'q' to quit\n");
}

// Handle keyboard input for menu navigation
int handleInput(Menu *menu) {
    int key = getch();
    
    // Check for arrow keys and vim-style navigation
    #ifdef _WIN32
    if (key == 224) { // Extended key code for Windows
        key = getch();
        switch (key) {
            case 72: // Up arrow
                menu->selected = (menu->selected - 1 + menu->count) % menu->count;
                break;
            case 80: // Down arrow
                menu->selected = (menu->selected + 1) % menu->count;
                break;
        }
    } else {
    #else
    if (key == 27 && kbhit()) { // ESC sequence for Linux
        getch(); // Skip '['
        key = getch();
        switch (key) {
            case 'A': // Up arrow
                menu->selected = (menu->selected - 1 + menu->count) % menu->count;
                break;
            case 'B': // Down arrow
                menu->selected = (menu->selected + 1) % menu->count;
                break;
        }
    } else {
    #endif
        switch (key) {
            case 'k': // vim-style up
                menu->selected = (menu->selected - 1 + menu->count) % menu->count;
                break;
            case 'j': // vim-style down
                menu->selected = (menu->selected + 1) % menu->count;
                break;
            case 'q': // quit
                return -1;
            case 13: // Enter key
                return menu->selected;
        }
    }
    
    return -2; // No selection made yet
}

int main() {
    Menu menu;
    initMenu(&menu);
    
    // Add some options to the menu
    addOption(&menu, "Option 1");
    addOption(&menu, "Option 2");
    addOption(&menu, "Option 3");
    addOption(&menu, "Option 4");
    addOption(&menu, "Exit");
    
    int result = -2;
    while (result == -2) {
        displayMenu(&menu);
        result = handleInput(&menu);
        
        // Small delay to prevent CPU hogging
        #ifdef _WIN32
        Sleep(50); // 50 milliseconds
        #else
        usleep(50000); // 50 milliseconds
        #endif
    }
    
    if (result >= 0) {
        clearScreen();
        printf("You selected: %s\n", menu.options[result]);
        
        // If the user selected "Exit" or the last option
        if (result == menu.count - 1) {
            printf("Exiting program...\n");
            return 0;
        }
        
        // Here you can add code to handle each specific menu option
        printf("Performing action for %s...\n", menu.options[result]);
    } else {
        clearScreen();
        printf("Menu closed. Goodbye!\n");
    }
    
    return 0;
}
