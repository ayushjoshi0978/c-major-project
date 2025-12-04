#ifndef BANKING_H
#define BANKING_H

typedef struct {
    int accno;
    char name[50];
    float balance;
} Account;


int next_account_number();
void create_account();
void deposit_money();
void withdraw_money();
void check_balance();
void display_all_accounts();

#endif
