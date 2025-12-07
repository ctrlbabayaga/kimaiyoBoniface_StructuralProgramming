#include <stdio.h>
#include "login.h"
#include "deposit.h"
#include "withdraw.h"
#include "balanceinquiry.h"



void login()
{
    int correctpin = 1234;
    int userpin;
    int choice;
    int extern balance;

    for (int i = 2; i >= 0; i--)
    {
        printf("Enter User Pin:\n");
        scanf("%d", &userpin);

        if (userpin == correctpin) {
            printf("Access granted\n");
            break;
        }

        printf("Incorrect pin.\n");
        printf("You have %d attempts remaining.\n", i);
    }

    if (userpin != correctpin) {
        printf("Access denied.\n");
        return;
    }

    printf("Choose an option:\n");
    printf("1. Balance inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Your balance is: %d\n", balance);
            break;

        case 2:
            deposit();
            break;

        case 3:
            withdraw();
            break;

        case 4:
            printf("Thank you for banking with us.\n");
            break;

        default:
            printf("Invalid option\n");
    }
}
