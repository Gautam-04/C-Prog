#include <stdio.h>

//Function Declaration
void Insertion(int nums[]);
void Deletion(int nums[]);
void Sorting(int nums[]);
void Searching(int nums[]);
void Merging(int nums[]);

int main(){
    int nums[100] = {10,52,41,26,35,20,9,1,25,54};
    int r;
    
    printf("\nChose a Method from the below list\n1.Insertion\n2.Deletion\n3.Sorting\n4.Searching\n5.Merging.\n Select a number to perform the particular task:- ");
    scanf("%d" , &r);

    if (1 <= r && r <= 5)
    {
        switch (r)
        {
        case 1:
        //Created function for each switch case
            Insertion(nums);
            break;
        case 2:
            Deletion(nums);
            break;
        case 3:
            Sorting(nums);
            break;
        case 4:
            Searching(nums);
            break;
        case 5:
            Merging(nums);
            break;
        default:
            break;
        };
    } else{
        printf("Enter Correct Number (Range 1-5)");
    }

    //original arr to compare
    int arr[100] = {10, 52, 41, 26, 35, 20, 9, 1, 25, 54};
    printf("\nCompare the above Array with the original Array \n Original Array is :- ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}  

//Performs Task for insertion
void Insertion(int nums[])
{  
    //I am considering Array size to be 10
    int n = 10;
    int y , pos , x , i;
    printf("Enter where you want to add your element:-\n1.Beginning\n2.End\n3.Random:- ");
    scanf("%d" , &y);
    if(1 <= y && y <= 3){
        if(y == 1){
            //adds element in the beginning
            printf("Enter the element you want to enter:- ");
            scanf("%d" , &x);
            //Since arr size will increase if a add a number
            n++;
            for (i = n; i > 0; i--)
            {
                nums[i] = nums[i - 1];
            }
            nums[0] = x;

            //print the matrix 
            printf("Updated array is :- ");
            for ( i = 0; i < n; i++)
            {
                printf("%d\t", nums[i]);
            }
            
            
        } else if(y == 2){
            //adds elements in the end
            printf("Enter the element you want to enter:- ");
            scanf("%d", &x);
            // Since arr size will increase if a add a number
            n++;
            nums[n - 1] = x;
            // print the matrix
            printf("Updated array is :- ");
            for (i = 0; i < n; i++)
            {
                printf("%d\t", nums[i]);
            }
        } else{
            //adds elements in any random location
            printf("Enter the element you want to enter:- ");
            scanf("%d", &x);
            printf("Enter the position You want to add element:- ");
            scanf("%d", &pos);
            n++;
            for (i = n; i > pos; i--)
            {
                nums[i] = nums[i - 1];
            }
            nums[pos] = x;
            printf("Updated array is :- ");
            for (i = 0; i < n; i++)
            {
                printf("%d\t", nums[i]);
            }
                }
    } else{
        printf("Enter number between 1 - 3");
    }

    }


//Performs Task for deletion
void Deletion(int nums[])
{
}

//Performs task for sorting
void Sorting(int nums[])
{
}

//Performs task for Searching
void Searching(int nums[])
{
}
// Performs task for Merging
void Merging(int nums[])
{
}