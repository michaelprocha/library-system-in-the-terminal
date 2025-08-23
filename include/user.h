#ifndef USER_H
#define USER_H

typedef struct users
{
    char name[50];
    int age;
    char cpf[11];
    int has_book;
} Users;

int user_options();
void users();

#endif