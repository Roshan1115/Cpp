#include<stdio.h>

int max(int,int);
int main(){
    int a,b,max_variavle;
    printf("Enter two numbeer which you want to compare.\n");
    scanf("%d%d",&a,&b);
    max_variavle= max(a,b);
    printf("\n%d is larger.",max_variavle);
    return 0;

}

int max(int num1,int num2){
    int result;
    if(num1>num2)
        result=num1;
    else
        result=num2;

    return result;
}