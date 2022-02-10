#include<iostream>
using namespace std;

int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10};

  for(int i=0;i<10;i++){
    for(int j=i; j<10; j++){
      for(int k=i; k<=j; k++){
        cout<<arr[k]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}

// use : g++ -std=c++11 