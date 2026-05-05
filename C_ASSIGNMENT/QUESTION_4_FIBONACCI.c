/*
AUTHOR : ANAGHA R
DATE   : 03/05/2026
PROGRAM TO GENERATE FIBONACCI SERIES
*/

#include <stdio.h>
int main()
{
    int number, first = 0, second = 1, next;

    printf("ENTER THE NUMBER OF TERMS : ");
    scanf("%d", &number);

    printf("FIBONACCI SERIES : ");

    for(int i = 0; i < number; i++)
    {
        if(i <= 1)
        {
            next = i;        //ince the first two nmbers are 0 and 1.
        }
        else
        {
            next = first + second;   //next  means thge sum of previous two numbers
            first = second;         //update the value of first with second
            second = next;          //update the value of second with next
        }
        printf("%d ", next);      //prit the next (sum of previous two numbers) in the series

    }


    return 0;
}