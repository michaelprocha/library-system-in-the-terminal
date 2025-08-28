#include "../include/home.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/system.h"
#include "../include/user.h"
#include "../include/book.h"
#include "../include/loans.h"

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
        users();
        break;

    case 2:
        books();
        break;

    case 3:
        loans();
        break;

    default:
        return; // Sair
    }
}