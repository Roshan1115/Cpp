#include<stdio.h>

int find_square(int num);

int main(){
    int a,square;
    printf("Enter the numver : ");
    scanf("%d", &a);
    square = find_square(a);
    printf("\nThe square of %d is %d", a, square);
    return 0;
}
int find_square(int num){
    int result = num*num;
    return result;
}