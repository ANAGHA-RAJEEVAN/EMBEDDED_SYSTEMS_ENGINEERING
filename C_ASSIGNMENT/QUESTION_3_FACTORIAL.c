/*
AUTHOR : ANAGHA R
DATE   : 03/05/2026
PROGRAM TO FIND THE FACTORIAL OF A NUMBER
*/

#include <stdio.h>
int main()
{
    int num ,i = 1, factorial = 1;

    printf("ENTER A WHOLE NUMBER : ");
    scanf("%d", &num);

    while(i <= num)      //Execute the loop until i is less than or equal tonum
    {
        factorial *= i;  //factorial = factorial * i
        i++;            //increment the value of i 
    }

    printf("FACTORIAL OF THE GIVEN NUMBER IS : %d", factorial);

    return 0;

}