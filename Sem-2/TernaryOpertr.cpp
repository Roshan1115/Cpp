#include<iostream>
using namespace std;

int main(){
    cout<<"Example of ternary operator"<<endl;
    int a,b;
    cout<<"Enter two values "<<endl;
    cin>>a>>b;
    (a > b) ? cout<<a<<" is larger than "<<b : cout<<b<<" is larger than "<<a;
    return 0;
}