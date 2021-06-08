#include<stdio.h>
int fact(int);
int main(){
    int n;
    printf("Enter the n value : ");
    scanf("%d",&n);
    printf("The factorial of %d is : %d",n,fact(n));

    return 0;
}
int fact(int num){
    if(num!=0)
    return (num * fact(num-1));
    else
    return (1);
}