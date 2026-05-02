/*
AUTHOR : ANAGHA R
DATE   : 02/05/2026
PROGRAM TO CHECK WHETHER THE NUMBER IS ODD OR EVEN
*/

#include <stdio.h>
int main()
{
    int num;
    printf("ENTER A WHOLE NUMBER: ");
    scanf("%d", &num);

    if(num%2 == 0)
    {
        printf("%d IS AN EVEN NUMBER.\n", num);
    }
    else
    {
        printf("%d IS AN ODD NUMBER.\n", num);
    }

    return 0;
}