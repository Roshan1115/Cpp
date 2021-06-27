// help to find the way to move the disk from A to C with using helper B and the bigger disc cannot be over the smaller disx

#include<iostream>
using namespace std;

void PowerOfHanoi(int n, char src, char dest, char helper){
  if(n==0) return;

  PowerOfHanoi(n-1, src, helper, dest);
  cout<<"Move from "<< src<<" to "<< dest<<endl;
  PowerOfHanoi(n-1, helper, dest, src);
}

int main(){
  /*
  A = Source
  B = Helper
  C = Destination
  */
  PowerOfHanoi(3, 'A', 'C', 'B');
  return 0;
}