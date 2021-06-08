#include<stdio.h>
int main(){
    int a=10;
    int *first_pointer;   // Initialized a pointer of name first_pointer
    first_pointer= &a;     //assigned the address of a to the first_pointer

    printf("The value of a is %d\n\n",*first_pointer);
    printf("The address in which a is stored is %p",first_pointer);
                // %p is the format specifier fo for pointer when it is returning an address.

    return 0;
}
