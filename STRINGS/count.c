#include<stdio.h>
#include<string.h>

int main(){
    char string[50];
    int i, vowels=0,digit=0,spaces=0,consonants=0;

    printf("Enter any string including all types of charcters:- ");
    fgets(string,sizeof(string),stdin);

    for ( i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
        {
            vowels++;
        } else if (string[i]>='0' && string[i]<='9')
        {
            digit++;
        } else if(string[i] == ' ')
        {
            spaces++;
        } else{
            consonants++;
        }
    }
    printf("Vowels:%d\nDigits:%d\nSpaces:%d\nConsonants:%d\n" , vowels, digit , spaces, consonants);

    return 0;
}