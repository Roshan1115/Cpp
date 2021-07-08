#include<iostream>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int d,x,y,z;
    cin>> d>> x>> y>> z;

    int strat1 = x*7;
    int strat2 = y*d + z*(7-d);

    cout<< max(strat1, strat2)<<endl;
  }
  return 0;
}