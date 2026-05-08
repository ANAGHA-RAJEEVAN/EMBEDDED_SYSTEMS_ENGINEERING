/*
AUTHOR : ANAGHA R
DATE   : 08/05/2026
PROGRAM TO IMPLEMENT AN ARITHMETIC CALCULATOR USING FUNCTIONS
*/

#include <stdio.h>
//Function prototypes
float add (float , float);
float subtract (float , float);
float multiply (float , float);
float divide (float , float);
float operation(char , float , float);

int main()
{
    float num1 , num2 , result;
    char operator;

    printf("ENTER THE FIRST NUMBER => ");
    scanf("%f", &num1);
    printf("ENTER THE SECOND NUMBER => ");
    scanf("%f", &num2);
    printf("ENTER THE OPERATOR \n + => ADDITION\n - => SUBTRACTION\n * => MULTIPLICATION\n / => DIVISION\n ");
    scanf(" %c", &operator);

    result = operation(operator, num1, num2);  //Call the operation function to perform arithmetic operatin

    if(operator == '/' && num2 == 0)     //check if operator is division and 2nd num is 0.
    {
        printf("DIVISION BY ZERO IS NOT ALLOWED.\n");   
    }
    else
    {
        printf("THE RESULT OF THE OPERATION => %f\n", result);
    }
    return 0;

}

float operation(char operator, float num1, float num2)
{
    float answer;
    switch(operator)
    {
        case '+':
            answer = add(num1,num2);
            break;

        case '-':
            answer = subtract(num1,num2);
            break;

        case '*':
            answer = multiply(num1,num2);
            break;

        case '/':
            answer = divide(num1,num2);
            break;

        default:
            printf("INVALID OPERATOR\n");
            return 0;
    }
    return answer;
}

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}