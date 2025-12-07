#include <stdio.h>
#include "deposit.h"

// Use the global balance
extern int balance;

void deposit()
{
    int amountToDeposit;

    printf("Enter the amount you wish to deposit:\n");
    scanf("%d", &amountToDeposit);

    balance += amountToDeposit;  // update the global balance
    printf("Deposit successful.\n");
    printf("Your new balance is: %d\n", balance);
}
