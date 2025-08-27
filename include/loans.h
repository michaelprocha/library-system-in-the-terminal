#ifndef LOANS_H
#define LOANS_H

typedef struct Loan
{
    char name[50];
    char cpf[11];
    char title[50];
    int id;
} Loan;

int loan_options();
void loans();
void save_loan(Loan *new_loan);
void register_loan();
void loan_list();

#endif