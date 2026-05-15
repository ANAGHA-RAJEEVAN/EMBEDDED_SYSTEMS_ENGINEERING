/*
    AUTHOR : ANAGHA R
    DATE   : 14/05/2026
    PROGRAM TO REMOVE MULTIPLE SPACES INTO A SINGLE SPACE FROM A STRING.
*/
#include <stdio.h>
int main()
{
    char string[100];
    printf("Enter a string : ");
    scanf("%[^\n]", string);
    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == ' ' && string[i+1] == ' ')
        {
            //shift to rmove extra space
            for(int j = i; string[j] != '\0'; j++)
            {
                string[j] = string[j+1];
            }
            i--; 
        }
    }
    
    printf("String after removing extra spaces : %s", string);
    return 0;
}