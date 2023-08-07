#include <stdio.h>

// Function prototypes
void Insertion(int nums[], int n);
void Deletion(int nums[], int n);
void Sorting(int nums[], int n);
void Searching(int nums[], int n);
void Merging(int nums[], int n);

int main()
{
    int n, r;
    int nums[100];

    // Input array size and elements
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Enter the elements in the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Save a copy of the original array
    int originalNums[100];
    for (int i = 0; i < n; i++)
    {
        originalNums[i] = nums[i];
    }

    int shouldContinue = 1;

    while (shouldContinue)
    {
        // Display menu for array operations
        printf("\nChoose a Method from the below list:\n1.Insertion\n2.Deletion\n3.Sorting\n4.Searching\n5.Merging.\n6.Exit\nSelect a number to perform the particular task: ");
        scanf("%d", &r);

        if (1 <= r && r <= 6)
        {
            switch (r)
            {
            case 1:
                Insertion(nums, n);
                break;
            case 2:
                Deletion(nums, n);
                break;
            case 3:
                Sorting(nums, n);
                break;
            case 4:
                Searching(nums, n);
                break;
            case 5:
                Merging(nums, n);
                break;
            case 6:
                shouldContinue = 0; // Set the flag to exit the loop
                break;
            default:
                printf("Invalid option.\n");
                break;
            };
        }
        else
        {
            printf("Enter Correct Number (Range 1-6)\n");
        }
    }

    // Print the original array for comparison
    printf("Compare the above Array with the original Array:\nOriginal Array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", originalNums[i]);
    }

    return 0;
}

void Insertion(int nums[], int n)
{
    int y, pos, x, i;
    int shouldContinue = 1;

    while (shouldContinue)
    {
        // Ask the user where they want to add the element
        printf("Enter where you want to add your element:\n1.Beginning\n2.End\n3.Random\n4.Exit: ");
        scanf("%d", &y);

        // Check if the input is valid (1, 2, 3, or 4)
        if (1 <= y && y <= 4)
        {
            if (y == 1)
            {
                // Add element in the beginning of the array
                printf("Enter the element you want to enter: ");
                scanf("%d", &x);

                // Since the array size will increase when we add a number
                n++;

                // Shift elements to the right to make space for the new element at the beginning
                for (i = n; i > 0; i--)
                {
                    nums[i] = nums[i - 1];
                }

                // Insert the new element at the beginning
                nums[0] = x;

                // Print the updated array
                printf("Updated array is: ");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", nums[i]);
                }
            }
            else if (y == 2)
            {
                // Add element in the end of the array
                printf("Enter the element you want to enter: ");
                scanf("%d", &x);

                // Since the array size will increase when we add a number
                n++;

                // Insert the new element at the end
                nums[n - 1] = x;

                // Print the updated array
                printf("Updated array is: ");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", nums[i]);
                }
            }
            else if (y == 3)
            {
                // Add element in any random location
                printf("Enter the element you want to enter: ");
                scanf("%d", &x);

                printf("Enter the position you want to add element: ");
                scanf("%d", &pos);

                // Check if the position is within the valid range
                if (pos >= 1 && pos <= n + 1)
                {
                    // Since the array size will increase when we add a number
                    n++;

                    // Shift elements to the right to make space for the new element at the desired position
                    for (i = n; i > pos - 1; i--)
                    {
                        nums[i] = nums[i - 1];
                    }

                    // Insert the new element at the desired position
                    nums[pos - 1] = x;

                    // Print the updated array
                    printf("Updated array is: ");
                    for (i = 0; i < n; i++)
                    {
                        printf("%d ", nums[i]);
                    }
                }
                else
                {
                    printf("Invalid position. Enter a position between 1 and %d.\n", n + 1);
                }
            }
            else if (y == 4)
            {
                shouldContinue = 0; // Set the flag to exit the loop
            }
        }
        else
        {
            printf("Invalid input. Enter a number between 1 and 4.\n");
        }
    }
}

// Function to perform Deletion in the array
void Deletion(int nums[], int n)
{
    int pos, i;
    int shouldContinue = 1;

    while (shouldContinue)
    {
        // Ask the user for the position of the element to delete
        printf("Enter the position you want to delete: ");
        scanf("%d", &pos);

        // Check if the position is within the valid range
        if (pos >= 1 && pos <= n)
        {
            // Reduce the array size by one to remove the element at the given position
            n--;

            // Shift elements to the left, starting from the position to delete
            for (i = pos - 1; i < n; i++)
            {
                nums[i] = nums[i + 1];
            }

            // Print the updated array after deletion
            printf("Updated array is: ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", nums[i]);
            }
        }
        else
        {
            printf("Invalid position. Enter a position between 1 and %d.\n", n);
        }

        // Ask if the user wants to continue or exit
        printf("\nDo you want to delete another element? (1: Yes, 0: No): ");
        scanf("%d", &shouldContinue);
    }
}

// Function to perform Sorting of the array using Bubble Sort algorithm
void Sorting(int nums[], int n)
{
    int i;
    // Bubble Sort: run the steps n-1 times
    for (int i = 0; i < n; i++)
    {
        // Each iteration, the largest element will 'bubble up' to its correct position
        for (int j = 1; j < n - i; j++)
        {
            // Compare adjacent elements and swap if necessary to bring the larger element to the right
            if (nums[j] < nums[j - 1])
            {
                // Swap the elements using a temporary variable
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
    // Print the sorted array
    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", nums[i]);
    }
}

// Function to perform Searching in the array
void Searching(int nums[], int n)
{
    int x, y = 0, z = -1, i;
    // Ask the user for the element to search
    printf("Enter the element you want to search: ");
    scanf("%d", &x);
    // Linear Search: Run the loop n times to search for the element in the array
    for (i = 0; i < n; i++)
    {
        if (x == nums[i])
        {
            // If the element is found, increment the counter 'y'
            y++;
            // Save the index of the first occurrence of the element in 'z'
            z = i + 1;
        }
    }
    // Check if the element is found or not based on the value of 'y'
    if (y == 1)
    {
        printf("Element is found at position %d\n", z);
    }
    else
    {
        printf("Element not found\n");
    }
}

void Merging(int nums[], int n)
{
    int a, merge[100];
    int merged[200]; // Assuming the maximum merged size is 200 (100 + 100)

    printf("Enter the Length of the array you want to merge: ");
    scanf("%d", &a);
    // Maximum value of a should be less than 100

    int final = a + n;

    printf("Enter the array elements:\n");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &merge[i]);
    }
    Sorting(nums,n);
    Sorting(merge,a);

    int i = 0, j = 0, k = 0;
    while (i < n && j < a)
    {
        if (nums[i] < merge[j])
        {
            merged[k] = nums[i];
            i++;
        }
        else
        {
            merged[k] = merge[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        merged[k] = nums[i];
        i++;
        k++;
    }

    while (j < a)
    {
        merged[k] = merge[j];
        j++;
        k++;
    }

    printf("The merged and sorted array is:\n");
    for (int m = 0; m < final; m++)
    {
        printf("%d ", merged[m]); // Add a space between elements for readability
    }

    printf("\n");
}