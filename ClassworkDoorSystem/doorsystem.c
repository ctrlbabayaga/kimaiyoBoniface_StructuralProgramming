#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A=5678;
    int B;
    int C;

    printf("Enter user PIN: ");
    scanf("%d", &B);

    if(B==A){
        printf("Access granted");
    }

    else{
        printf("Wewe ni mwizi");
    }


    if (B==A){

        printf("Choose an option:\n");
        printf("1. Open door\n");
        printf("2. Change username\n");
        printf("3. Change pin\n");
        printf("4. Exit\n");
    }
    scanf("%d", &C);

    switch(C){
case 1:
    printf("Door is opening\n");
    break;
case 2:
    printf("New username\n");
    break;
case 3:
    printf("Input new pin\n");
    break;
case 4:
    printf("Bye bye\n");
    break;

default:
    printf("Invalid option");
    }
    return 0;
}
