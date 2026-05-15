/*
    AUTHOR : ANAGHA R
    DATE   : 14/05/2026
    PROGRAM TO REPLACE BITS IN A NUMBER FROM ANOTHER.
*/

#include <stdio.h>
int main() 
{
    int num1,num2,position,n;

    printf("Enter the first number : ");
    scanf("%d", &num1);

    printf("Enter the second number : ");
    scanf("%d", &num2);

    printf("Enter the starting position : ");
    scanf("%d", &position);

    printf("Enter the number of bits : ");
    scanf("%d", &n);

    int mask = (1 << n)-1;
    num1 &= ~(mask << position-n+1); // Clear n bits

     num2 = (num2 & mask) << position-n+1; // extract  n bits from num2 
    num1 |= num2; // replace buts in num1 from num2

    printf("The resulting number is : %d\n", num1);
    return 0;
}