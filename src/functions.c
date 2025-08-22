#include <stdio.h>
#include <stdlib.h>
#include "../include/system.h"
#include "../include/structs.h"

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

int user_options()
{
    int option;
    printf("------------------------------------------------------\n");
    printf("-----    Digite o número da opção desejada!    -------\n");
    printf("1 - Cadastrar novo usuário\n");
    printf("2 - Ver lista de usuários\n");
    printf("3 - Voltar\n");
    printf("Digite: ");
    scanf("%d", &option);
    clean_screen();
    return option;
}

void users()
{
    const int option = user_options();
    switch (option)
    {
    case 1:
        /* cadastra novo usuario */
        break;

    case 2:
        /* ver lista de usuarios */
        break;

    default:
        return;
        break;
    }
}

void decision(int option)
{
    switch (option)
    {
    case 1:
        users();
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