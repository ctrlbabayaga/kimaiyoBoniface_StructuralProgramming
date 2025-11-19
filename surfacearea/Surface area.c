#include <stdio.h>
#include <stdlib.h>

int main()
{
    const double PI=3.14;
          double r;
          double s_area;

    printf("Enter the radius of the sphere:");
    scanf("%lf", &r);

    s_area= (4* PI * r* r);
    printf("Answer is:%f", s_area);



    return 0;
}
