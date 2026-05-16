/*
AUTHOR : ANAGHA R
DATE   : 15/05/2026
PROGRAM TO FIND 2ND LARGEST AND 2ND SMALLEST ELEMENTS IN AN ARRAY.
*/

#include <stdio.h>
int main()
{

    int arr[50],size,largest,second_largest,smallest,second_smallest;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &size);

    printf("Enter the elements of the array : ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    smallest = arr[0];
//2nd largest element
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > largest)  //If arr[i] >largest,then update 2nd largest with largest and largest with arr[i]
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }
//2nd smallest element
    for(int i = 1; i < size; i++)
    {
        if(arr[i] < smallest)  //If arr[i] < smallest,then update 2nd smallest with smallest and smallest with arr[i]
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
    }

    printf("The 2nd largest element is : %d\n", second_largest);
    printf("The 2nd smallest element is : %d\n", second_smallest);
}