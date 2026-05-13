/*
    AUTHOR : ANAGHA R
    DATE   : 11/05/2026
    PROGRAM TO CONVERT INTEGER TO STRING.
*/

#include <stdio.h>
int main()
{
    int num, i = 0;
    char str[20];
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    // Convert integer to string
    while (num > 0) 
    {
        str[i] = (num % 10) + '0'; //convert integer to character
        num /= 10; 
        i++;
    }
    str[i] = '\0'; // End the string with null character
    
    // Reverse the string to get correct order
    for (int j = 0; j < i / 2; j++) 
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    
    printf("The string after converion is: %s\n", str);
    
    return 0;
}

