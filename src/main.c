#include <stdio.h>
#include "../include/banking.h"

int main() {
    int choice;

    while (1) {
        printf("\n=== BANK MANAGEMENT SYSTEM ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: create_account(); break;
        case 2: deposit_money(); break;
        case 3: withdraw_money(); break;
        case 4: check_balance(); break;
        case 5: display_all_accounts(); break;
        case 0: return 0;
        default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
