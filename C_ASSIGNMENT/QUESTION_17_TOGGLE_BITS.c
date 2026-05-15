/*
    AUTHOR : ANAGHA R
    DATE   : 14/05/2026
    PROGRAM TO TOGGLE BITS IN A NUMBER From a position. 
*/

#include <stdio.h>
int main()
{
    int number, position, n;
    printf("Enter a number : ");  
    scanf("%d", &number);
    printf("Enter the starting bit position : ");  //Enter the starting bit positio
    scanf("%d", &position);
    printf("Enter the number of bits to toggle : "); //Enter the number of bits to toggle
    scanf("%d", &n);

    
    int mask = ((1 << n) - 1);  // Create a mask 
    mask <<= position-n+1; // Shift the mask to the correct starting position

    // Toggling bits
    number ^= mask;

    printf("Number after toggling bits: %d\n", number);
    return 0;
}