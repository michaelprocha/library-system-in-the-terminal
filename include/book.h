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

#endif