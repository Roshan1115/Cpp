#include<stdio.h>
int main(){
    int fn,sn,i,j;
    printf("Enter the first and second number bellow : \n");
    printf("\nEnter first number : ");
    scanf("%d",&fn);
    printf("Enter second number : ");
    scanf("%d",&sn);
    printf("\n\n The prime number(s) between %d and %d are :\n\n",fn,sn);
   
   
    for (i=fn; i<=sn; i++){
        for (j=2; j<i; j++){
            if(i%j==0){
                break;
            }
        }
        if(j==i){
            printf("%d ",i);
        }
    }
printf("\n\n\n");




    return 0;
}