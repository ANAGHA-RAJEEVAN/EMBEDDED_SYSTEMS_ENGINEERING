/*
AUTHOR : ANAGHA R
DATE   : 15/05/2026
PROGRAM TO ADD TWO COMPLEX NUMBERS USING STRUCTURES
*/

#include <stdio.h>

//Structure to store complex number
struct Complex
{
    int real;
    int imaginary;
};

// Function declaration
struct Complex add(struct Complex, struct Complex);
void display(struct Complex);

int main()
{
    struct Complex num1, num2, result;

    printf("ENTER THE REAL PART OF THE 1ST COMPLEX NUMBER : ");
    scanf("%d", &num1.real);

    printf("ENTER THE IMAGINARY PART OF THE 1ST COMPLEX NUMBER : ");
    scanf("%d", &num1.imaginary);

    printf("ENTER THE REAL PART OF THE 2ND COMPLEX NUMBER : ");
    scanf("%d", &num2.real);

    printf("ENTER THE IMAGINARY PART OF THE 2ND COMPLEX NUMBER : ");
    scanf("%d", &num2.imaginary);

    // Function call to add complex numbers 
    result = add(num1, num2);

    printf("SUM OF THE COMPLEX NUMBERS : ");
    display(result);

    return 0;
}

// Function to add two complex numbers
struct Complex add(struct Complex a, struct Complex b)
{
    struct Complex temp;

    temp.real = a.real + b.real;
    temp.imaginary = a.imaginary + b.imaginary;

    return temp;
}

//Function to display complex numb
void display(struct Complex num)
{
    if(num.imaginary >= 0)
    {
        printf("%d + %di\n", num.real, num.imaginary);
    }
    else
    {
        printf("%d - %di\n", num.real, -num.imaginary);
    }
}