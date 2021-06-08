#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    if(a > b){
        cout<<a<<" is larger than "<<b;
    }
    if(b > a){
        cout<<b<<" is larger than "<<a;
    }
    return 0;
}