#ifndef BOOK_H
#define BOOK_H

typedef struct books
{
    char title[50];
    char author[50];
    int id;
    int total_quantity;
    int quantity;
} Books;

#endif