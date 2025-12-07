#include <stdio.h>
#include "withdraw.h"

// Use this as a shared balance variable
extern int balance;

void withdraw()
{
    int amountToWithdraw;
    int anotherTransaction;

    printf("Enter the amount you wish to withdraw:\n");
    scanf("%d", &amountToWithdraw);

    if (amountToWithdraw > balance) {
        printf("Insufficient funds. Please top up.\n");
        printf("Press 1 for another transaction, 2 to exit:\n");
        scanf("%d", &anotherTransaction);

        if (anotherTransaction == 1) {
            withdraw();  // call again
        }

        return; // leave the function
    }

    // Enough balance → process withdrawal
    balance -= amountToWithdraw;
    printf("Withdrawal successful.\n");
    printf("Your new balance is: %d\n", balance);
}
