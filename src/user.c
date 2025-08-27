#include "../include/user.h"
#include "../include/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void save_user(User *new_user)
{
    FILE *user = fopen("../data/users.txt", "a");
    if (user == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    fprintf(user, "%s;%d;%s;%c;",
            new_user->name,
            new_user->age,
            new_user->cpf,
            new_user->has_book);
    fclose(user);
    printf("Usuário cadastrado!\n");
    pause_screen();
    clean_screen();
}

void register_user()
{
    User new_user;

    getchar();
    printf("------------------------------------------------------\n");
    printf("-------       Cadastrando novo usuário!      ---------\n");
    printf("Nome completo: ");
    fgets(new_user.name, 50, stdin);
    new_user.name[strcspn(new_user.name, "\n")] = '\0';
    printf("Idade: ");
    scanf("%d", &new_user.age);
    printf("CPF (apenas núnmeros): ");
    scanf("%11s", new_user.cpf);
    new_user.has_book = 'N';

    clean_screen();
    save_user(&new_user);
}

void user_list()
{
    FILE *user = fopen("../data/users.txt", "r");

    if (user == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    User view_user;

    while (fscanf(user, "%49[^;];%d;%11[^;];%c;",
                  view_user.name,
                  &view_user.age,
                  view_user.cpf,
                  &view_user.has_book) == 4)
    {

        printf("Nome: %s,  Idade: %d,  CPF: %s, Tem livro: %c",
               view_user.name,
               view_user.age,
               view_user.cpf,
               view_user.has_book);
        printf("\n-------------------------------------------------------------------------------------\n");
    }

    fclose(user);
    pause_screen();
    clean_screen();
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
    int option;
    do
    {
        int option = user_options();
        switch (option)
        {
        case 1:
            register_user();
            break;

        case 2:
            user_list();
            break;

        default:
            return;
            break;
        }
    } while (option != 3);
}