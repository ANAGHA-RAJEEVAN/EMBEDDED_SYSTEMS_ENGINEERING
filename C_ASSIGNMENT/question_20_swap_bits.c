/*
    AUTHOR : ANAGHA R
    DATE   : 14/05/2026

    PROGRAM TO SWAP BITS BETWEEN TTWO NUMBERS 
*/

#include <stdio.h>
int main()
{
    int num1, num2, position, n;

    printf("Enter the first number : ");
    scanf("%d", &num1);

    printf("Enter the second number : ");
    scanf("%d", &num2);

    printf("Enter the starting position : ");
    scanf("%d", &position);

    printf("Enter the number of bits : ");
    scanf("%d", &n);

    int mask = (1 << n) - 1; // mask

    // Extractingbits from num1 and num2
    int num1bit = (num1 >> position) & mask;
    int num2bit = (num2 >> position) & mask;

    // Clear n bits in both numbers
    num1 &= ~(mask << position);
    num2 &= ~(mask << position);

    // Swap the bits
    num1 |= (num2bit << position);
    num2 |= (num1bit << position);

    printf("After swapping \n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);

    return 0;
}