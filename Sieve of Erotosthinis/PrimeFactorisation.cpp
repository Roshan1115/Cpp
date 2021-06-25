// prime factorisation of a number using the concept of 
// sieve of erotosthisis

#include<iostream>
using namespace std;

void factorise(int n){
  // spf is smallest prime number 
  int spf[100] = {0};
  for(int i=0; i<100; i++){
    spf[i] = i;
  }
  for(int i=2; i<=n; i++){
    if(spf[i] == i){
    for(int j= i*i; j<=n; j += i){
      if(spf[j] == j){
      spf[j] = i;
      }
    }
    }
  }

  while(n != 1){
    cout<<spf[n]<< " ";
    n = n/ spf[n];
  }
}

int main(){
  int n;
  cin>>n;
  factorise(n);
  return 0;
}