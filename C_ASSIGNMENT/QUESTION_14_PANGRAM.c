/*
    AUTHOR : ANAGHA R
    DATE   : 13/05/2026
    PROGRAM TO CHECK IF A STRING IS A PANGRAM OR NOT.
*/

#include <stdio.h>
int main()
{
    char string[100];
    int flag = 0;
    printf("Enter a string: ");
    scanf("%[^\n]", string);

    int alphabet[26] = {0}; // array to store alphabet prsesence
    for(int i =0; string[i] != '\0'; i++)
    {
        if(string[i] >= 'a' && string[i] <= 'z')  //lower case
        {
            alphabet[string[i] - 'a'] = 1; 
        }
        else if(string[i] >= 'A' && string[i] <= 'Z') //upper case
        {
            alphabet[string[i] - 'A'] = 1; 
        }
    }

    for(int i=0; i<26; i++)
    {
        if(alphabet[i] == 0)
        {
            flag = 1;   //If any alphabt is not there,then it is not a pangram
            break;
        }
    }
    if(flag == 0)
    {
        printf("The string is a pangram.\n");
    }
    else
    {
        printf("The string is not a pangram.\n");
    }
}
