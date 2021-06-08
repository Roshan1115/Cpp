#include<iostream>
using namespace std;

int main(){
  int t, n, number_4 = 0;
  cin>>t;
  while(t--){
    cin>>n;
    while(n > 0){
      if(n%10 == 4) number_4 += 1;
      n = n/10;
    }
    cout<<number_4<<endl;
    number_4 = 0;
  }
  return 0;
}
