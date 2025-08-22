#include <stdio.h>
#include <stdlib.h>
#include "../include/system.h"

int home_screen()
{
    int option;
    printf("------------------------------------------------------\n");
    printf("-----    Digite o número da opção desejada!    -------\n");
    printf("1 - Usuários / 2 - Livros / 3 - Empréstimos / 4 - Sair\n");
    printf("Digite: ");
    scanf("%d", &option);
    clean_screen();
    return option;
}

void decision(int option)
{
    switch (option)
    {
    case 1:
        /* Usuarios */
        break;

    case 2:
        /* Livros */
        break;

    case 3:
        /* Empréstimos */
        break;

    default:
        return; // Sair
    }
}