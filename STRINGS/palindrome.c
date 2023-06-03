#include<stdio.h>
#include<string.h>

int isPalindrome(const char*str){
int len = strlen(str);
int i,j;
for ( i = 0, j = len - 1 ;i<j; i++ , j--)
{
    if (str[i] != str[j])
    {
        return 0;
    }
}
return 1; 
}

int main(){
    char str[100];
    printf("Enter A string:- ");
    fgets(str , sizeof(str),stdin);

    str[strcspn(str,"\n")] = '\0';
    if(isPalindrome(str)){
        printf("Entered String is a palindrome\n");
    } else {
        printf("Enter String is not a palindrome\n");
    }
    return 0;
}