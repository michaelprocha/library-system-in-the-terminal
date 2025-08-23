#include <stdio.h>
#include <stdlib.h>
#include "../include/system.h"

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