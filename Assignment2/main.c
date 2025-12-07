#include <stdio.h>
#include "deposit.h"
#include "withdraw.h"
#include "login.h"
#include "balanceInquiry.h"

int balance = 1000; // starting balance
int choice;
int main() {
    login();
    do{
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



     while(choice!=4);
    return 0;


}
