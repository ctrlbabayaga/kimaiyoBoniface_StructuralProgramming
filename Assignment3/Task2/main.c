#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 10;
    int *ptr =&num;
     printf("Value of num %p: \n",num);
      printf("Value of ptr %p: \n",*ptr);
    return 0;
}
