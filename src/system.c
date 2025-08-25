#include "../include/system.h"
#include <stdio.h>
#include <stdlib.h>

void pause_screen() {
    #ifdef _WIN32
        system("pause");    // Windows
    #else
        printf("Pressione ENTER para continuar...");   // Linux e macOS
        while (getchar() != '\n');
    #endif
}

void clean_screen() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux e macOS
    #endif
}