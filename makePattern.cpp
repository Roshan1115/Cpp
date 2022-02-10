#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter n\n";
  cin >> n;
  int size = n + n-1;


  //taking valid input
  while(size < 1){
    cout<<"Please enter value of n greater than 0\n";
    cin>> n;
    size = n + n-1;
  }

  int arr[size][size];
  int s = size;



  // main logic including 3 for loops
  for(int k=0; k<s; k++){
    for(int i=k; i<s; i++){
      for(int j=k; j<s; j++){
        if(i == k || j == k || i==s-1 || j==s-1)
          arr[i][j] = n;
      }
    }
    s--; n--;
  }



  //display
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  return 0;
}



// use : g++ -std=c++11 