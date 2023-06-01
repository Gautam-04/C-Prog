// WAP to check whether the number is odd and even.

#include<stdio.h>

int main()
{
    int num;
    printf("Enter A Number:");
    scanf("%d" , &num);

    if (num%2 == 0)
    {
        printf("The Given Number is Even.");
    }
    else{
        printf("The Given Number is Odd");
    }

    return 0;
    
}