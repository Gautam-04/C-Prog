//WAP to print all three digit Armstrong nos

#include <stdio.h>

int main()
{
    int min = 100, max = 999;
    int i, digit, sum;

    printf("Armstrong numbers between %d and %d:\n", min, max);

    for (i = min; i <= max; i++)
    {
        digit = i;
        sum = 0;
        while (digit > 0)
        {
            int cube = (digit % 10) * (digit % 10) * (digit % 10);
            sum += cube;
            digit /= 10;
        }
        if (sum == i)
        {
            printf("%d\n", i);
        }
    }

    return 0;

}
