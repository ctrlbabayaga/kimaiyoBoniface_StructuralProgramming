#include <stdio.h>
#include <stdlib.h>
void swapNumbers(int* a,int* b ){
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}


int main()
{
    int a = 10;
    int b = 20;
    printf("Before swap\n");
    printf("Value of a: %d\n",a);
    printf("Value of b: %d\n",b);

    swapNumbers(&a,&b);

    printf("After swap\n");
    printf("Value of a: %d\n",a);
    printf("Value of b: %d\n",b);
    return 0;
}
