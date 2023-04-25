//WAP TO FIND SQUARE OF A NUMBER

#include <stdio.h>
long power(int a, int b);

long power(int a, int b)
{
    long result = 1;
    for (int i = 1; i <= b; i++)
    {
        result *= a;
    }
    return result;
}
int main()
{
    int num1;
    printf("Enter base: ");
    scanf("%d", &num1);
    long result = power(num1, 2);
    printf("The result = %ld", result);
    return 0;
}
