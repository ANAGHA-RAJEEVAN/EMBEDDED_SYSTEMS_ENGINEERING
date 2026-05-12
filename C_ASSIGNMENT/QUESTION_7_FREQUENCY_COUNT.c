/*
AUTHOR : ANAGHA R
DATE   : 08/05/2026
PROGRAM TO FIND FREQUENCY COUNT OF DIGITS IN A NUMBER.
*/

#include <stdio.h>
//Function prototyp
void count(int, int*);

int main()
{
    int num;
    int freq[10] = {0};  //array to store count

    printf("ENTER AN INTEGER : ");
    scanf("%d", &num);

    if(num == 0)   //If number is 0, then count of 0 is 1
    {
        freq[0] = 1;
        printf("Digit %d => %d times\n", 0, freq[0]); 
    }
    else if(num < 0)   //check if num is positive
    {
        printf("PLEASE ENTER A POSITIVE INTEGER.\n");
    }
    else
    {
        count(num, freq);  //Calling count function 

        for(int i = 0; i < 10; i++)
        {
            printf("Digit %d => %d times\n", i, freq[i]);  //print the count
        }
    }
    return 0;
}

//Function to count frequency of digits in a number
void count(int number, int *frequency)
{
    int digit;

    while(number > 0)  
    {
        digit = number % 10;  
        frequency[digit]++;    
        number /= 10;         
    }
}