#include<iostream>
using namespace std;

int main(){
  int t, sum = 0, n;
  cin>>t;
  while(t--){
    cin>>n;
    while(n){
      sum = sum + (n % 10);
      n = n/10;
    }
    cout<<sum<<endl;
    sum = 0;
  }
  return 0;
}

