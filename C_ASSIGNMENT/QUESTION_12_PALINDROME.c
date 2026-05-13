/*
    AUTHOR : ANAGHA R
    DATE   : 12/05/2026
    PROGRAM TO CHECK WHETHER A STRING IS A PALINDROME OR NOT.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int flag = 0;
    printf("Enter a string: ");
    scanf("%s", string);

    int length = strlen(string);
    for(int i =0; i <length/2; i++)
    {
        if(string[i] != string[length-i-1])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}