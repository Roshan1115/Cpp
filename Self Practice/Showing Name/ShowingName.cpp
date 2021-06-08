#include<iostream>
#include<string>
using namespace std;

    int n;
    char fname[20],lname[20],ch;
    
void optans(int x);
void askInput();

void askData(){
    cout<<"Enter your first name : ";
    cin>>fname;
    cout<<"Enter your last name : ";
    cin>>lname;
    askInput();
}
void askInput(){
    cout<<"\nWhat way you want to see your name ?\n1. First Name\n2. last Name\n3.  Full name\n\nYour Answer : ";
    cin>>n;
    if (n >= 1 && n <= 3){
        optans(n);
    }
    else{
        cout<<"Please enter the valid option."<<endl;
        askInput();
    }
}


int main(){
    askData();
    return 0;
}


void optans(int x){

    if(x==1)
{
    cout<<"\nYou have selected 1.\n";
    cout<<endl<<fname<<endl;
}
else if(x==2){
    cout<<"Y\nou have selected 2.\n";
    cout<<endl<<lname<<endl;
}
else if(x==3){
    cout<<"\nYou have selected 3.\n";
    cout<<endl<<fname<<" "<<lname<<endl;
}
}