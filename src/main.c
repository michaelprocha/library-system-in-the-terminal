#include <stdio.h>  //Standard input and output.
#include <string.h> //string manipulation
#include <stdlib.h> //memory manipulation or system
#include <stddef.h> //definition of null and size
#include <locale.h> //set language
#include "../include/structs.h"
#include "../include/system.h"
#include "../include/functions.h"

int main()
{
    setlocale(LC_ALL, "pt_BR.utf8"); // Git Bash, Linux e macOS

    int option;

    do
    {
        option = home_screen();
        decision(option);
    } while (option != 4);

    return 0;
}
