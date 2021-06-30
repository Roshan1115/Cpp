#include<iostream>
#include<vector>
using namespace std;

bool compare(int a, int b){
  return a > b;
}

int main(){
  vector<int> p;
  for(int i=0; i<5; i++){
    int value;
    cin>> value;
    p.push_back(value);
    value = 0;
  }

  for(int i :p){
    cout<<i<<"   ";
  }
  cout<<endl;

  sort(p.begin(), p.end(), compare);    // in decending order

  for(int i :p){
    cout<<i<<"   ";
  }
  cout<<endl;
  return 0;
}