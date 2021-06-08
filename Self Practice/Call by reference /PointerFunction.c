#include<stdio.h>

void salaryHike(float *var, float bon);

int main(){
    float salary = 0; 
    float bonous = 0;
    
    printf("Enter the salary ; ");
    scanf("%f",&salary);
    printf("Enter the hike ; ");
    scanf("%f",&bonous);
    salaryHike(&salary,bonous);
    printf("The updated salary is : %f",salary);
    
    return 0;
}
void salaryHike(float *var, float bon){
    *var = *var*bon;
}







