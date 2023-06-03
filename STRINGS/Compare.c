#include<stdio.h>

main(){
    int flag=0,i;
    char s1[20], s2[20];

    printf("Print First String: ");
    gets(s1);

    printf("Enter Second String: ");
    gets(s2);

    for ( i = 0; s1[i]!= '\0' || s2[i] != '\0'; i++)
    {
        if(s1[i]!=s2[i]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        printf("The String Are Same\n");
    } else{
        printf("The string are not same\n");
    }
    
}