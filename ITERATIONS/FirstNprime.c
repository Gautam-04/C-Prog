#include <stdio.h>

int main()
{
    int n, i, j, count;

    printf("Enter the value of n:\n ");
    scanf("%d", &n);

    // The first two prime numbers are 2 and 3
    printf("The first %d prime numbers are:\n", n);
    printf("2\n");
    printf("3\n");

    // Check for prime numbers starting from 5
    for (i = 5, count = 2; count < n; i += 2)
    {
        for (j = 3; j * j <= i; j += 2)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j * j > i)
        {
            printf("%d\n", i);
            count++;
        }
    }

    return 0;
}
