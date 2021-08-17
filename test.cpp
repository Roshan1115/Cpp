#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int arr[5] = {3,7,4,32,4};
  sort(arr, arr + 5);

  for(int i=0; i<5; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}