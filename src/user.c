#include "../include/user.h"
#include "../include/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void save_user(User *new_user)
{
    FILE *user = fopen("../data/users.txt", "a");
    if (user == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    fprintf(user, "%s %d %s %c\n", new_user->name, new_user->age, new_user->cpf, new_user->has_book);
    fclose(user);
    printf("Usuário cadastrado!\n");
    pause_screen();
    clean_screen();
}

void register_user()
{
    User new_user;

    printf("------------------------------------------------------\n");
    printf("-------       Cadastrando novo usuário!      ---------\n");
    printf("Nome: ");
    scanf("%19s", new_user.name);
    printf("Idade: ");
    scanf("%d", &new_user.age);
    printf("CPF (apenas núnmeros): ");
    scanf("%11s", new_user.cpf);
    new_user.has_book = 'N';

    clean_screen();
    save_user(&new_user);
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
        register_user();
        break;

    case 2:
        /* ver lista de usuarios */
        break;

    default:
        return;
        break;
    }
}