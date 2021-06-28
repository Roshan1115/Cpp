// count the number of path from starting path to ending path in game board
// given that you can jump in an option between 1-6

#include<iostream>
using namespace std;

int countPath(int s, int e){
  if(s==e){
    return 1;
  }
  if(s>e){
    return 0;
  }
  int count = 0;
  for(int i=1; i<=6; i++){
    count += countPath(s+i, e);
  }
  return count;
}

int main(){
  cout<< countPath(0, 3);
  return 0;
}