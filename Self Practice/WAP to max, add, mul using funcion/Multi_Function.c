#include <stdio.h>

int max_funcion(int num1, int num2);
int addition(int num3, int num4);
int subtract(int num5, int num6);
int multiply(int num7, int num8);

int main()
{
    int a, b, Max, sum, subtracted, product;

    printf("Enter first number number to find maximum : ");
    scanf("%d", &a);
    printf("Enter second number to find maximum : ");
    scanf("%d", &b);
    Max = max_funcion(a, b);
    printf("The largest number is %d\n\n", Max);

    printf("Enter first number for addition : ");
    scanf("%d", &a);
    printf("Enter second number for addition : ");
    scanf("%d", &b);
    sum = addition(a, b);
    printf("The sum of both numvers is %d\n\n", sum);

    printf("Enter first number for Subtraction : ");
    scanf("%d", &a);
    printf("Enter second number for Subtraction : ");
    scanf("%d", &b);
    subtracted = subtract(a, b);
    printf("The value after subtraction is %d\n\n", subtracted);

    printf("Enter first number for Multiplication : ");
    scanf("%d", &a);
    printf("Enter second number for Multiplication : ");
    scanf("%d", &b);
    product = multiply(a,b);
    printf("THe product of both the numvers is %d\n\n", product);

    return 0;
}

int max_funcion(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}
int addition(int num3, int num4)
{
    int result = num3 + num4;
    return result;
}
int subtract(int num5, int num6)
{
    int result = num5 - num6;
    return result;
}
int multiply(int num7, int num8)
{
    int result = num7 * num8;
    return result;
}