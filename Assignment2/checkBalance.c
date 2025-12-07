#include <stdio.h>
#include "balanceInquiry.h"

// Use global balance
extern int balance;

void checkBalance() {
    printf("Your current balance is: %d\n", balance);
}
