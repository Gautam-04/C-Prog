#include <stdio.h>

void main(){
 int a[50] , n, num, i, j, flag=0;

 printf("Enter Number of Array Elemnts:- ");
 scanf("%d" ,&n);

printf("Enter Array Elemenst: ");
for ( i = 0; i < n; i++)
{
    scanf("%d" , &a[i]);
}

printf("Enter Element You want to Search:- ");
scanf("%d" , &num);

for ( i = 0; i < n; i++)
{
    if(num==a[i]){
        flag = 1;
        break;
    } 
}
if(flag==1){
    printf("The Number Is Found in The Array");
} else{
    printf("The Number Is Not Pesent In The Array");
}

}