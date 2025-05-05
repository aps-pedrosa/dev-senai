#include <stdio.h>
#include <windows.h>

#define UP_ARROW VK_UP
#define DOWN_ARROW VK_DOWN
#define ENTER_KEY VK_RETURN

// Function to capture key input
int getKey() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD inputRecord;
    DWORD events;

    while (1) {
        ReadConsoleInput(hInput, &inputRecord, 1, &events);
        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            return inputRecord.Event.KeyEvent.wVirtualKeyCode;
        }
    }
}

// Function to display the menu
void displayMenu(char *options[], int numOptions, int selected) {
    system("cls"); // Clear screen
    for (int i = 0; i < numOptions; i++) {
        if (i == selected) {
            printf(" > %s\n", options[i]); // Highlight the selected option
        } else {
            printf("   %s\n", options[i]);
        }
    }
}

int main() {
    // Define menu options
    char *options[] = {"Option 1", "Option 2", "Option 3", "Exit"};
    int numOptions = sizeof(options) / sizeof(options[0]);
    int selected = 0;

    while (1) {
        // Display the menu
        displayMenu(options, numOptions, selected);

        // Capture key input
        int key = getKey();

        // Check for arrow keys or Enter
        if (key == UP_ARROW) {
            selected = (selected - 1 + numOptions) % numOptions; // Navigate up
        } else if (key == DOWN_ARROW) {
            selected = (selected + 1) % numOptions; // Navigate down
        } else if (key == ENTER_KEY) { // Enter key
            if (selected == numOptions - 1) {
                printf("\nExiting...\n");
                break;
            } else {
                printf("\nYou selected: %s\n", options[selected]);
                printf("Press any key to return to the menu...\n");
                getKey(); // Wait for user input
            }
        }
    }

    return 0;
}