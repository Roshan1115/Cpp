
#include <stdio.h>
int main () {
     int n[10];     // n is an array of 10 integer
     int i;
     printf("Enter the number : \n" );
     
     //initialize elements of array n to 0
     
     for ( i = 0; i < 10; i++ ){
     scanf("%d",&n[i]);
    }
    printf("The enteed values are : \n");
    
     for ( i = 0; i < 10; i++ ){   
     printf("%d\n",n[i]);
    }

    return 0;
         
     }

