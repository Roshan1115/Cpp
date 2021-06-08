#include <stdio.h>
int print(int,int,int);
int main()
{
    int a, b, c, d, final;
    a = 10;
    b = 20;
    c = 30;
    d = 40;
    print(a,b,c);
    return 0;
}
int print(int num1,int num2,int num3)
{

    printf("The value of a is %d \n", num1);
    printf("The value of b is %d \n", num2);
    printf("The value of c is %d \n", num3);
    return 0;
}