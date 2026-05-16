/*
AUTHOR : ANAGHA R
DATE   : 15/05/2026
PROGRAM TO FIND ALL PAIRS WITH GIVEN TARGET SUM
*/

#include <stdio.h>
int main()
{
    int arr[50], length, sum, i, j;

    printf("Enter the number of elements in the array :");
    scanf("%d", &length);

    printf("Enter the elements of the array :");
    for (i = 0; i < length; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the sum :");
    scanf("%d", &sum);

    printf("Pairs with sum %d are:\n", sum);
    for (i = 0; i < length; i++) 
    {
        for (j = i + 1; j < length; j++) 
        {
            if (arr[i] + arr[j] == sum)   // Chek if the sum arr[i] and arr[j] =sum
            {
                printf("(%d,%d)\n", arr[i],arr[j]);
            }
        }
    }

    return 0;
}