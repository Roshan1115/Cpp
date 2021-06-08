#include<stdio.h>

int max_funcion(int num1, int num2);

int main(){
    int a,b,Max;
    printf("Enter teh value of a : ");
    scanf("%d", &a);
    printf("Enter teh value of b : ");
    scanf("%d", &b);
    Max = max_funcion(a,b);
    printf("The largest number is %d", Max);
    return 0;
}

int max_funcion(int num1, int num2){
    if (num1>num2){
        return num1;
    }
    else{
        return num2;
    }
}