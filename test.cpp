#include<iostream>
#include<vector>
using namespace std;

void change(vector<int> a){
  for(int i=0; i<5; i++){
    a[i] = i +  10;
  }

  for(int i : a){
    cout<< i<<" ";
  }cout<<endl;
}

int main(){
  vector<int> v(5);

  for(int& i : v){
    cin>> i;
  }
  

  for(int i : v){
    cout<< i<<" ";
  }cout<<endl;

  change(v);

  for(int i : v){
    cout<< i<<" ";
  }cout<<endl;

  return 0;
}