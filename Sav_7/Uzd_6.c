#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*funcs[])());
void startApp();
void openOptions();
void exitApp();

int main() {
    char *title = "Main Menu";
    char *options[] = { "Start", "Options", "Exit" };
    int size = 3;
    char *msg = "Choose an option's number:";
    void (*funcs[])() = { startApp, openOptions, exitApp };

    showMenu(title, options, size, msg, funcs);

    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*funcs[])()) {
    int success = 0;
    int n;
    do {
        printf("%s\n", menuTitle);
        for (int i = 0; i < menuSize; i++) {
            printf("%d - %s\n", i, menuOptions[i]);
        }
        printf("%s\n", inputMsg);

        success = scanf("%d", &n) && n >= 0 && n < menuSize; 
        while (getchar() != '\n')
            ;
    } while (!success);

    funcs[n]();

    return n;
}

void startApp() {
    printf("Starting the app...\n");
}

void openOptions() {
    printf("Going to the options...\n");
}

void exitApp() {
    printf("Exiting the program...\n");
}