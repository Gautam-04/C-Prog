#include <stdio.h>
void printEven(int cur, int limit);
int main()
{
    int lowerLimit, upperLimit;
    printf("Enter lower limit: ");
    scanf("%d", &lowerLimit);
    printf("Enter upper limit: ");
    scanf("%d", &upperLimit);

    printf("Even Numbers from %d to %d are: ", lowerLimit, upperLimit);
    printEven(lowerLimit, upperLimit);

    return 0;
}
void printEven(int cur, int limit)
{
    if (cur > limit)
        return;

    printf("%d, ", cur);
    printEven(cur + 2, limit);
}