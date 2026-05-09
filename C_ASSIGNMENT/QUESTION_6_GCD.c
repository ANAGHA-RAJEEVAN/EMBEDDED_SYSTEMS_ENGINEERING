/*
AUTHOR : ANAGHA R
DATE   : 08/05/2026
PROGRAM TO FIND GCD USING RECURSION
*/

#include <stdio.h>
//Function prototype
int gcd(int, int);

int main()
{
    int num1, num2, result;

    printf("ENTER THE 1ST NUMBER : ");
    scanf("%d",&num1);
    printf("ENTER THE 2ND NUMBER : ");  
    scanf("%d",&num2);

    if(num1 < 0 || num2 < 0)   //check if the numbers are positive
    {
        printf("PLEASE ENTER POSITIVE NUMBERS.\n");
    }
    else
    {
        result = gcd(num1, num2);  //Calling gcd function 

        printf("THE GCD OF %d AND %d IS => %d\n", num1, num2, result);
    }
    return 0;
}

//Function to calculate GCD usig recursion
int gcd(int a, int b)
{
    int c;

    if (b == 0)           //If 2nd number is 0,then GCD is the 1st number
    {
        return a;
    }
    else if (a == 0)      //If 1st number is 0,then GCD is the 2nd number
    {
        return b;
    }
    else
    {
        c = a % b;         //remainder of a / b
        return gcd(b, c);  //recursive call with b and remainder of a / b (c).
    }
}