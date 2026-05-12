/*
    AUTHOR : ANAGHA R
    DATE   : 08/05/2026
    PROGRAM TO CONVERT STRING TO INTEGER.
*/

#include <stdio.h>
int main()
{
    char string[100];  //to store strng
    int result =0;   //to store number after converting

    printf("ENTER A NUMBER AS A STRING : ");
    scanf("%s", string);
    for(int i =0; string[i] != '\0';i++)  
    {
        int digit = string[i] - '0';    //character to integer
        result = result * 10 + digit; 
    }

    printf("THE CONVERTED INTEGER IS : %d\n", result);
    return 0;
}