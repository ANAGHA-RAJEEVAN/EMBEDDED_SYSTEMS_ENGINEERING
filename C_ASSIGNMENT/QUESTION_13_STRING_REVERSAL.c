/*
    AUTHOR : ANAGHA R
    DATE   : 12/05/2026
    PROGRAM TO REVERSE A STRING.
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char string[100];
    printf("Enter a string: ");
    scanf("%[^\n]", string);

    int length = strlen(string);
    // Reverse the string
    for(int i =0;i<length/2;i++)
    {
        char temp = string[i];
        string[i] = string[length-i-1];
        string[length-i-1] = temp;
    }
    printf("The reversed string is: %s\n", string);
    return 0;
}