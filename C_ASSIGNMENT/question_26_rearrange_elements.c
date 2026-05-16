/*
AUTHOR : ANAGHA R
DATE   : 15/05/2026
PROGRAM TO REARRANGE ARRAY SO THAT NEGATIVE NUMBERS APPEAR BEFORE POSITIVE NUMBERS in sorted order
 */

#include <stdio.h>

int main()
{
    int arr[100], temp[100];
    int size, i, j = 0;

    printf("ENTER THE SIZE OF THE ARRAY : ");
    scanf("%d", &size);

    printf("ENTER THE ARRAY ELEMENTS :");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
// negative number storing
    for(i = 0; i < size; i++)
    {
        if(arr[i] < 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }
// positive number storing
    for(i = 0; i < size; i++)
    {
        if(arr[i] >= 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }

    printf("REARRANGED ARRAY : ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", temp[i]);
    }
    printf("\n");
    return 0;
}