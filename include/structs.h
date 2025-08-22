#ifndef PEOPLE_H
#define PEOPLE_H

typedef struct people
{
    char name[50];
    int age;
    char cpf[11];
    int has_book;
} People;

typedef struct books
{
    char title[50];
    char author[50];
    int id;
    int total_quantity;
    int quantity;
} Books;

typedef struct loans
{
    char name[50];
    char cpf[11];
    char title[50];
    int id;
} Loans;

#endif