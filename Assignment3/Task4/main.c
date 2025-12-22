#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 10;
    int num2 = 20;
    int *pNum1 = &num1;
    int *pNum2 = &num2;
    int sum;
    sum = *pNum1 + *pNum2;
    printf("The answer is :%d ", sum);
    return 0;
}
