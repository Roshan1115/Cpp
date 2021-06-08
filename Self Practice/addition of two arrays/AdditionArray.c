#include<stdio.h>
int main(){
    int a[11],b[11],c[11];
    printf("Enter the values for first array :\n");
    for(int i=0; i<=5; i++){
        scanf("%d",&a[i]);
        
    }
     printf("Enter the values for second array :\n");
    for(int i=0; i<=5; i++){
        scanf("%d",&b[i]);
        
    }
    printf("The sum of both arrays is : \n");
    for(int i=0; i<=5; i++){
        c[i]=a[i]+b[i];
        printf("%d ",c[i]);
    }
    
    return 0;
}








