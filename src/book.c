#include "../include/book.h"
#include "../include/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void save_book(Book *new_book)
{
    FILE *book = fopen("../data/books.txt", "a");
    if (book == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    fprintf(book, "%s;%s;%d;%d;%d;",
            new_book->title,
            new_book->author,
            new_book->total_quantity,
            new_book->quantity,
            new_book->id);
    fclose(book);
    printf("Livro cadastrado!\n");
    pause_screen();
    clean_screen();
}

void register_book()
{
    Book new_book;
    getchar();
    printf("------------------------------------------------------\n");
    printf("--------       Cadastrando novo livro!      ----------\n");
    printf("Titulo do livro: ");
    fgets(new_book.title, 50, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0';
    printf("Autor: ");
    fgets(new_book.author, 50, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0';
    printf("Quantidade de livros: ");
    scanf("%d", &new_book.total_quantity);
    printf("Id do livro: ");
    scanf("%d", &new_book.id);
    new_book.quantity = new_book.total_quantity;

    clean_screen();
    save_book(&new_book);
}

void book_list()
{
    FILE *book = fopen("../data/books.txt", "r");

    if (book == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    Book view_book;

    while (fscanf(book, "%49[^;];%49[^;];%d;%d;%d;",
                  view_book.title,
                  view_book.author,
                  &view_book.total_quantity,
                  &view_book.quantity,
                  &view_book.id) == 5)
    {

        printf("Titulo: %s  Autor: %s  Quantidade total: %d  Quantidade disponivel: %d  ID: %d",
               view_book.title,
               view_book.author,
               view_book.total_quantity,
               view_book.quantity,
               view_book.id);
        printf("\n---------------------------------------------------------------------------------------\n");
    }

    fclose(book);
    pause_screen();
    clean_screen();
}

int book_options()
{
    int option;
    printf("------------------------------------------------------\n");
    printf("-----    Digite o número da opção desejada!    -------\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Ver lista de livros\n");
    printf("3 - Voltar\n");
    printf("Digite: ");
    scanf("%d", &option);
    clean_screen();
    return option;
}

void books()
{
    int option;
    do
    {
        int option = book_options();
        switch (option)
        {
        case 1:
            register_book();
            break;

        case 2:
            book_list();
            break;

        default:
            return;
            break;
        }
    } while (option != 3);
}