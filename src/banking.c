#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/banking.h"

const char *FILENAME = "accounts.dat";

// Auto-increment account number 
int next_account_number() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 1001;

    Account a;
    int last = 1000;
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.accno > last) last = a.accno;
    }
    fclose(fp);
    return last + 1;
}

// Create a new account 
void create_account() {
    Account a;
    a.accno = next_account_number();

    printf("Enter name: ");
    getchar();
    fgets(a.name, sizeof(a.name), stdin);
    a.name[strcspn(a.name, "\n")] = 0;

    printf("Enter initial deposit: ");
    scanf("%f", &a.balance);

    FILE *fp = fopen(FILENAME, "ab");
    fwrite(&a, sizeof(Account), 1, fp);
    fclose(fp);

    printf("\nAccount created successfully!\n");
    printf("Account No: %d\nName: %s\nBalance: %.2f\n\n", a.accno, a.name, a.balance);
}

// Help to find and modify account 
int update_account(int accno, float amount, int type) {
    FILE *fp = fopen(FILENAME, "r+b");
    if (!fp) return 0;

    Account a;
    long pos = 0;

    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.accno == accno) {

            if (type == 1) a.balance += amount;      // deposit
            if (type == 2 && amount <= a.balance) a.balance -= amount; // withdraw
            else if (type == 2 && amount > a.balance) {
                printf("Insufficient balance!\n");
                fclose(fp);
                return 0;
            }

            fseek(fp, pos, SEEK_SET);
            fwrite(&a, sizeof(Account), 1, fp);
            fclose(fp);
            printf("Updated Balance: %.2f\n", a.balance);
            return 1;
        }
        pos += sizeof(Account);
    }
    fclose(fp);
    return 0;
}

// Deposit 
void deposit_money() {
    int acc;
    float amt;
    printf("Enter account number: ");
    scanf("%d", &acc);

    printf("Enter deposit amount: ");
    scanf("%f", &amt);

    if (!update_account(acc, amt, 1))
        printf("Account not found.\n");
}

// Withdraw 
void withdraw_money() {
    int acc;
    float amt;
    printf("Enter account number: ");
    scanf("%d", &acc);

    printf("Enter withdrawal amount: ");
    scanf("%f", &amt);

    if (!update_account(acc, amt, 2))
        printf("Account not found or insufficient funds.\n");
}

// Check balance 
void check_balance() {
    int acc;
    printf("Enter account number: ");
    scanf("%d", &acc);

    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) { printf("No accounts exist.\n"); return; }

    Account a;
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.accno == acc) {
            printf("Account: %d\nName: %s\nBalance: %.2f\n", a.accno, a.name, a.balance);
            fclose(fp);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(fp);
}

// Show all accounts 
void display_all_accounts() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) { printf("No accounts found.\n"); return; }

    Account a;
    printf("\n---- All Accounts ----\n");
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        printf("%d  |  %-20s | %.2f\n", a.accno, a.name, a.balance);
    }
    printf("----------------------\n\n");
    fclose(fp);
}
