//Whether the character entered through the keyboard is a lower case or not

#include <stdio.h>

int main(){
    char Ch;
    printf("Please Enter Any Character:\n");
    scanf("%c" , &Ch);
    if(Ch >= 97 && Ch<= 122){
        printf("The Above Character Is A Lower Case");
    } else{
        printf("Entered Character Is Not A Lower Case");
    }
    
    return 0;
}