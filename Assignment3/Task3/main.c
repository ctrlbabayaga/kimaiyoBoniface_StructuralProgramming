#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 100;
    int *pCount = &count;
    *pCount=95;
    printf("The updated value is: %d ", *pCount);
    return 0;
}
