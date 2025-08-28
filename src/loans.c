#include "../include/loans.h"
#include "../include/user.h"
#include "../include/book.h"
#include "../include/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void save_loan(Loan *new_loan)
{
    FILE *loan = fopen("../data/loans.txt", "a");
    if (!loan)
    {
        printf("Erro ao abrir loans.txt\n");
        pause_screen();
        clean_screen();
        return;
    }

    FILE *book = fopen("../data/books.txt", "r");
    FILE *user = fopen("../data/users.txt", "r");
    if (!book || !user)
    {
        printf("Erro ao abrir arquivos\n");
        pause_screen();
        clean_screen();
        fclose(loan);
        return;
    }

    User view_user;
    Book view_book;
    int registered = 0;
    int new_quantity = 0;
    char user_found = 0;
    char book_found = 0;

    while (fscanf(user, "%49[^;];%d;%11[^;];",
                  view_user.name, &view_user.age, view_user.cpf) == 3)
    {
        if (strcmp(view_user.cpf, new_loan->cpf) == 0)
        {
            user_found = 1;
            strncpy(new_loan->name, view_user.name, sizeof(new_loan->name) - 1);
            new_loan->name[sizeof(new_loan->name) - 1] = '\0';
        }
    }

    while (fscanf(book, "%49[^;];%49[^;];%d;%d;%d;",
                  view_book.title, view_book.author, &view_book.total_quantity,
                  &view_book.quantity, &view_book.id) == 5)
    {
        if (view_book.id == new_loan->book_id)
        {
            book_found = 1;
            new_quantity = view_book.quantity - 1;
            strncpy(new_loan->title, view_book.title, sizeof(new_loan->title) - 1);
            new_loan->title[sizeof(new_loan->title) - 1] = '\0';
        }
    }

    fclose(user);
    fclose(book);

    if (!user_found)
    {
        printf("Usuário não encontrado!\n");
        pause_screen();
        clean_screen();
        fclose(loan);
        return;
    }
    if (!book_found)
    {
        printf("Livro não encontrado!\n");
        pause_screen();
        clean_screen();
        fclose(loan);
        return;
    }

    fprintf(loan, "%s;%s;%s;%d;%d;", new_loan->name, new_loan->cpf, new_loan->title, new_loan->book_id, new_loan->id);
    printf("Empréstimo registrado\n");
    fclose(loan);

    FILE *f_books = fopen("../data/books.txt", "r");
    FILE *tmp_books = fopen("../data/books_tmp.txt", "w");

    while (fscanf(f_books, "%49[^;];%49[^;];%d;%d;%d;",
                  view_book.title, view_book.author,
                  &view_book.total_quantity, &view_book.quantity, &view_book.id) == 5)
    {
        if (view_book.id == new_loan->book_id)
        {
            view_book.quantity = new_quantity;
        }

        fprintf(tmp_books, "%s;%s;%d;%d;%d;",
                view_book.title, view_book.author,
                view_book.total_quantity, view_book.quantity, view_book.id);
    }

    fclose(f_books);
    fclose(tmp_books);

    remove("../data/books.txt");
    rename("../data/books_tmp.txt", "../data/books.txt");

    pause_screen();
    clean_screen();
}

void register_loan()
{
    Loan new_loan;
    getchar();
    printf("------------------------------------------------------\n");
    printf("--------       Cadastrando novo empréstimo!      ----------\n");
    printf("CPF: ");
    scanf(" %11s", new_loan.cpf);
    new_loan.cpf[sizeof new_loan.cpf - 1] = '\0';
    printf("Id livro: ");
    scanf("%d", &new_loan.book_id);
    printf("Id do emprestimo: ");
    scanf("%d", &new_loan.id);
    new_loan.name[0] = '\0';
    new_loan.title[0] = '\0';

    clean_screen();
    save_loan(&new_loan);
}

void loan_list()
{
    FILE *loan = fopen("../data/loans.txt", "r");

    if (loan == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    Loan view_loan;

    while (fscanf(loan, "%49[^;];%11[^;];%49[^;];%d;%d;",
                  view_loan.name,
                  view_loan.cpf,
                  view_loan.title,
                  &view_loan.book_id,
                  &view_loan.id) == 5)
    {

        printf("Nome: %s  CPF: %s  Titulo do livro: %s  ID do livro: %d  ID do emprestimos: %d",
               view_loan.name,
               view_loan.cpf,
               view_loan.title,
               view_loan.book_id,
               view_loan.id);
        printf("\n---------------------------------------------------------------------------------\n");
    }

    fclose(loan);
    pause_screen();
    clean_screen();
}

void return_book(Loan *old_loan)
{
    FILE *loans = fopen("../data/loans.txt", "r");
    if (!loans)
    {
        printf("Erro ao abrir loans.txt\n");
        pause_screen();
        clean_screen();
        return;
    }
    FILE *f_books = fopen("../data/books.txt", "r");
    if (!f_books)
    {
        printf("Erro ao abrir books.txt\n");
        pause_screen();
        clean_screen();
        return;
    }

    Loan view_loan;
    int delete_book_id;

    char loan_found = 0;

    while (fscanf(loans, "%49[^;];%11[^;];%49[^;];%d;%d;",
                  view_loan.name, view_loan.cpf, &view_loan.title,
                  &view_loan.book_id, &view_loan.id) == 5)
    {
        if (view_loan.id == old_loan->id)
        {
            loan_found = 1;
            delete_book_id = view_loan.book_id;
        }
    }

    if (!loan_found)
    {
        printf("Empréstimo não encontrado!\n");
        pause_screen();
        clean_screen();
        fclose(loans);
        return;
    }

    rewind(loans);

    Book view_book;
    FILE *tmp_loans = fopen("../data/loans_tmp.txt", "w");
    FILE *tmp_books = fopen("../data/books_tmp.txt", "w");

    while (fscanf(loans, "%49[^;];%11[^;];%49[^;];%d;%d;",
                  view_loan.name, view_loan.cpf, &view_loan.title,
                  &view_loan.book_id, &view_loan.id) == 5)
    {
        if (view_loan.id != old_loan->id)
        {
            fprintf(tmp_loans, "%s;%s;%s;%d;%d;", view_loan.name, view_loan.cpf, view_loan.title, view_loan.book_id, view_loan.id);
        }
    }

    while (fscanf(f_books, "%49[^;];%49[^;];%d;%d;%d;",
                  view_book.title, view_book.author,
                  &view_book.total_quantity, &view_book.quantity, &view_book.id) == 5)
    {
        if (view_book.id == delete_book_id)
        {
            view_book.quantity++;
        }
        fprintf(tmp_books, "%s;%s;%d;%d;%d;", view_book.title, view_book.author, view_book.total_quantity, view_book.quantity, view_book.id);
    }

    fclose(loans);
    fclose(f_books);
    fclose(tmp_books);
    fclose(tmp_loans);

    remove("../data/loans.txt");
    rename("../data/loans_tmp.txt", "../data/loans.txt");
    remove("../data/books.txt");
    rename("../data/books_tmp.txt", "../data/books.txt");

    printf("Livro devolvido!\n");

    pause_screen();
    clean_screen();
}

void register_return()
{
    Loan old_loan;
    printf("------------------------------------------------------\n");
    printf("--------------    Devolvendo livro!    ---------------\n");
    printf("Qual o ID do empréstimo: ");
    scanf("%d", &old_loan.id);
    return_book(&old_loan);
}

int loan_options()
{
    int option;
    printf("------------------------------------------------------\n");
    printf("-----    Digite o número da opção desejada!    -------\n");
    printf("1 - Registrar empréstimo\n");
    printf("2 - Registrar devolução\n");
    printf("3 - Ver lista de empréstimos\n");
    printf("4 - Voltar\n");
    printf("Digite: ");
    scanf("%d", &option);
    clean_screen();
    return option;
}

void loans()
{
    int option;
    do
    {
        int option = loan_options();
        switch (option)
        {
        case 1:
            register_loan();
            break;

        case 2:
            register_return();
            break;

        case 3:
            loan_list();
            break;

        default:
            return;
            break;
        }
    } while (option != 4);
}