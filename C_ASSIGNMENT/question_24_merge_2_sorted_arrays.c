/*
    AUTHOR : ANAGHA R
    DATE   : 15/05/2026  
    PROGRAM TO MERGE TWO SORTED ARRAYS INTO A SINGLE SORTED ARRAY.

*/

#include <stdio.h>
int main()
{
    int arr1[50], arr2[50], merged[100];
    int length1, length2, i, j, k;

    printf("Enter the number of elements in 1st array :");
    scanf("%d", &length1);

    printf("Enter the elements of the 1st array :");
    for (i = 0; i < length1; i++) 
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in 2nd array :");
    scanf("%d", &length2);
    printf("Enter the elements of the 2nd array :");
    for (i = 0; i < length2; i++) 
    {
        scanf("%d", &arr2[i]);
    }

    // Merging the two sorted arrays
    i = j = k = 0;
    while (i < length1 && j < length2) 
    {
        if (arr1[i] < arr2[j]) 
        {
            merged[k] = arr1[i];
            i++;
        } 
        else 
        {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1
    while (i < length1) 
    {
        merged[k] = arr1[i];
        i++;
        k++;
    }
    // Copy remaining elements of arr2
    while (j < length2) 
    {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    printf("Merged sorted array : ");
    for (i = 0; i < k; i++) 
    {
        printf("%d ", merged[i]);
    }
}