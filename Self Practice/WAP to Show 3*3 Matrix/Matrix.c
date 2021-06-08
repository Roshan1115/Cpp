#include<stdio.h>

int main(){
    int a[3][3];
    printf("Please enter the elements for the 3*3 martix ;\n");
    for(int i=0; i<3; i++){
         for(int j=0; j<3; j++){
             scanf("%d",&a[i][j]);
         }
    }
    printf("\n\nThe value of the Matrix is : \n");
    for(int i=0; i<3; i++){
         for(int j=0; j<3; j++){
             printf("%d ", a[i][j]);
         }
         printf("\n");
    }

    return 0;
}