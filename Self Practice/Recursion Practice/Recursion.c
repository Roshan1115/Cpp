#include<stdio.h>

int addTotal(int num1);
void main(){
    int n,total_sum;
    printf("Enter the number to which you want the sum of : ");
    scanf("%d",&n);

    total_sum = addTotal(n);
    printf("The final result of the addition is : %d  ",total_sum);
}

int addTotal(int num1){
    if (num1!= 0){
        return (num1 + addTotal(num1-1));
    }
    else{
        return num1;
    }
}