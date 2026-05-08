/*
AUTHOR : ANAGHA R
DATE   : 03/05/2026
PROGRAM TO CHECK WHETHR A NUMBER IS PERFECT OR NOT
*/

#include <stdio.h>

int perfect_number(int num);   //Function prototype 
int main()
{
    int number;

    printf("Enter a Number : ");
    scanf("%d", &number);

    if(number <= 0)      //chck whether number is a positive integer
    {
        printf("Please enter a positive integer.\n");
        return 0; 
    }

    int result = perfect_number(number);   //Call the function to check whether number is perfe4ct or not.

    if(result == number)
    {
        printf("%d is a Perfect Number.\n", number);
    }
    else
    {
        printf("%d is not a Perfect Number.\n", number);

    }

    return 0;
}

int perfect_number(int num)
{
    int sum = 0;
    for(int i = 1; i < num ; i++)
    {
        if(num % i == 0)   //If the number is divisible by i,its a factor of the number
        {
            sum += i;  //Add the factor to te sum
        }
    }
    return sum;    //Return the sum of the factors
}