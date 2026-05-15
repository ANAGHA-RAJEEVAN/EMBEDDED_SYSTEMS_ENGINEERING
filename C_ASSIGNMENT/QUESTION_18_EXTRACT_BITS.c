/*
    AUTHOR : ANAGHA R
    DATE   : 14/05/2026
    PROGRAM TO EXTRACT BITS FROM A SPECIFIC POSITION. 
*/

#include <stdio.h>
int main()
{
    int num,position,n;

    printf("Enter a number : ");
    scanf("%d", &num);

    printf("Enter the starting position : ");
    scanf("%d", &position);

    printf("Enter the number of bits : ");
    scanf("%d", &n);

    int mask = (1 << n)-1;  //mask
    int result = (num >> (position-n+1)) & mask; // shift to right to extract the bits

    printf("Extracted bits: %d\n", result);
    return 0;
}