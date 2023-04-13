// WAP to accept three numbers and display the greatest number

#include <stdio.h>

int main()
{
int N1 , N2 , N3 ;

printf("Enter First Number: ");
scanf("%d" , &N1);

printf("Enter Second Number: ");
scanf("%d", &N2);

printf("Enter Third Number: ");
scanf("%d", &N3);

if(N1 > N2 && N1 > N3)
{
    printf("\n The Greatest Number is = %2d" , N1);
} else if (N3>N2){
    printf("\n The Greatest Number is = %2d" , N3);
}
else{
    printf("\n The Greatest Number is = %2d", N2);
}

return 0;
}