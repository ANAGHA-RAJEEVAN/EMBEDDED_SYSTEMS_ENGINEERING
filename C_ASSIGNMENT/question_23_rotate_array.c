/*
    AUTHOR : ANAGHA R
    DATE   : 15/05/2026     
    PROGRAM TO ROTATE AN ARRAY TO THE LEFT OR RIGHT BY A GIVEN NUMBER OF POSITIONS.

*/

#include <stdio.h>
int main()
{
    int arr[50], length,n,i,j;
    char direction;

    printf("Enter the number of elements in the array :");
    scanf("%d", &length);

    printf("Enter the elements of the array :");
    for (i = 0; i < length; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate :");
    scanf("%d", &n);

    printf("Enter the direction to rotate (L-LEFT,R-RIGHT) : ");
    scanf(" %c", &direction);

    n = n % length; // Handle cases where n is greater than array size

    if (direction == 'L' || direction == 'l') 
    {
        // Rotate left
        while(n>0)
        {
            int temp = arr[0];
            for (i = 0; i < length - 1; i++) 
            {
                arr[i] = arr[i + 1];
            }
            arr[length - 1] = temp;
            n--;
        }
    } 
    else if (direction == 'R' || direction == 'r') 
    {
        // Rotate right
        while(n>0)
        {
            int temp = arr[length - 1];
            for (i = length - 1; i > 0; i--) 
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
            n--;
        }
    }
    else 
    {
        printf("Invalid direction! Please enter L or R.\n");
        return 1;
    }
    printf("Array after rotation : ");
    for (i = 0; i < length; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}