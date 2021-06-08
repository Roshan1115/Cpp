#include<iostream>
#include<stdio.h>

using namespace std;
struct student{
    char name[40];
    int roll,marks;

};
int main(){
    int n;
    cout<<"How many students are there ?"<<endl;
    cin>>n;
    struct student s[n];     //Initializig array of type student of size n
    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<i+1<<". "<<"Enter the student's data ;\n";
        cout<<"Enter Name : ";
        cin>>s[i].name;
        cout<<"Enter Roll Number : ";
        cin>>s[i].roll;
        cout<<"Enter Marks : ";
        cin>>s[i].marks;
        cout<<endl;
    }
    cout<<"The data of the students are : "<<endl;

    for(int i=0; i<n; i++){
        cout<<i+1<<". "<<"Student's data ;\n";
        cout<<"Name : "<<s[i].name<<endl;
        cout<<"Roll.No : "<<s[i].roll<<endl;
        cout<<"Marks : "<<s[i].marks<<endl;
        
        cout<<endl;
    }


   


    return 0;
}