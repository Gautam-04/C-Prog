// Swap 2 nos. (ii) without temp variable

#include <stdio.h>

int main()
{
    double x, y ;

    printf("Enter First Number:");
    scanf("%lf", &x);

    printf("Enter Second Number:");
    scanf("%lf", &y);

   x = x - y;
   y = x + y;
   x = y - x;

    printf("\nAfter swapping, first number = %.2lf\n", x);
    printf("After swapping, second number = %.2lf", y);
    return 0;
}
