// Swap 2 nos. (i)with  temp variable

#include<stdio.h>

int main()
{
    double x , y , t ;
    
    printf("Enter First Number:");
    scanf("%lf" , &x);

    printf("Enter Second Number:");
    scanf("%lf" , &y);

    t = x;
    x = y;
    y = t;

    printf("\nAfter swapping, first number = %.2lf\n", x);
    printf("After swapping, second number = %.2lf", y);
    return 0;
}