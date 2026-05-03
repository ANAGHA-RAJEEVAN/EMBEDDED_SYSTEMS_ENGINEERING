/*
AUTHOR : ANAGHA R
DATE   : 02/05/2026
PROGRAM TO CHECK WHETHER THE NUMBER IS pRIME OR NOT
*/

#include <stdio.h>
int main()
{
    int num, flag = 0;
    printf("ENTER A NUMBER: ");
    scanf("%d", &num);

    if(num == 1)           //check whether number is 1. 1 is neither a prime number nor a composite number.
    {
        printf("%d IS NEITHER A PRIME NUMBER NOR A COMPOSITE NUMBER.\n", num);
        return 0;
    }
    if(num < 1)             //check whether number is less than 1.
    {
        printf("INVALID INPUT.\n");
        return 0;
    }

    for (int i = 2; i * i <= num; i++)  // Executing loop for i=2 and checking the condition i*i<=num.
    {
        if (num % i == 0)     // if number is divisible by i, then it is not a prime number. So flag = 1 and break the loop.
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("%d IS A PRIME NUMBER.\n", num);
    }
        
    else
    {
        printf("%d IS NOT A PRIME NUMBER.\n", num);
    }

    return 0;

}