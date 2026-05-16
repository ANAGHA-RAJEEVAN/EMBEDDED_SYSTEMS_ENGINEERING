/*
AUTHOR : ANAGHA R
DATE   : 15/05/2026
PROGRAM TO REMOVE DUPLICATE ELEMENTS FROM AN ARRAY.

*/

#include <stdio.h>
int main()
{
    int arr[100], length, i, j, k;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &length);

    printf("Enter the elements of the array : ");
    for (i = 0; i < length; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Removng duplicate elemnts from array
    for (i = 0; i < length; i++) 
    {
        for (j = i + 1; j < length; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                // Shift elements to left
                for (k = j; k < length - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                length--; // decrese the length of array
                j--; 
            }
        }
    }

    printf("Array after removing duplicates : ");
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}