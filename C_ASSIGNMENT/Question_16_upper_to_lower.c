/*
    AUTHOR : ANAGHA R
    DATE   : 11/05/2026
    PROGRAM TO CONVERT A STRING FROM UPPER CASE TO LOWER CASE.
*/

#include <stdio.h>
int main()
{
    char string[100];

    printf("Enter a string : ");
    scanf("%[^\n]", string);
    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32; // 'a' - 'A' = 32,so add 32 to convert to lowercase
        }
    }
    printf("The string after converting to lower case is : %s\n", string);
}