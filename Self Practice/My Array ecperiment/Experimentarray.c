#include<stdio.h>
int main(){
    int array[2000];
    char ch;
    printf("Enter f for magic : \n");
    scanf("%c",&ch);
    if(ch=='f'){
        for (int i=0; i<2000; i++){
            array[i]=i+10;
            printf("%d ", array[i]);
        }
    }


    return 0;
}