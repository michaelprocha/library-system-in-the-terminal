#ifndef BOOK_H
#define BOOK_H

typedef struct book
{
    char title[50];
    char author[50];
    int id;
    int total_quantity;
    int quantity;
} Book;

int book_options();
void books();
void save_book(Book *new_book);
void register_book();
void book_list();

#endif