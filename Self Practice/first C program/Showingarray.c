#include<stdio.h>
int main()
{
    int a[3][3];
    printf("Enter the elements of the 3 x 3 Array :\n");
    for( int i=0; i<3; i++)
    {
        for( int j=0; j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe array is : \n\n");
    for( int i=0; i<3; i++)
    {
       printf("|     ");
        for( int j=0; j<3;j++)
        {
            printf("%d",a[i][j]);
            printf(" ");
            if( j==2)
            {
                printf("    |");
                printf("\n");

            }
        }
    }
    printf("\n");



    return 0;
}