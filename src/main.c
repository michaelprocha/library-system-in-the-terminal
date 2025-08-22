#include <stdio.h>  //Standard input and output.
#include <string.h> //string manipulation
#include <stdlib.h> //memory manipulation
#include <stddef.h> //definition of null and size
#include <locale.h> //set language
#include "../include/structs.h"
#include "../include/system.h"

int main()
{
    setlocale(LC_ALL, "pt_BR.utf8"); // ou "pt_BR.UTF-8" no Linux
    
    printf("Iniciando o projeto\n");
    pause_screen();
    return 0;
}
