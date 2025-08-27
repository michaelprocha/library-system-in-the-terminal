#ifndef USER_H
#define USER_H

typedef struct user
{
    char name[50];
    int age;
    char cpf[12];
    char has_book;
} User;

int user_options();
void users();
void save_user(User *new_user);
void register_user();
void user_list();

#endif