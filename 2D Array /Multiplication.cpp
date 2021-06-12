// display product of two differenct square matrix

#include<iostream>
using namespace std;

int main(){
  int n1,n2,n3;
  cin>>n1>>n2>>n3;
  int a[n1][n2];
  int b[n2][n3];
  int sum[n1][n3];
  cout<<"Enter first array element.\n";
  for(int i=0; i<n1; i++){
    for(int j=0; j<n2; j++)
      cin>>a[i][j];
  }
  cout<<"Enter Second array element.\n";
  for(int i=0; i<n2; i++){
    for(int j=0; j<n3; j++)
      cin>>b[i][j];
  }

  // initiating all values of sum as zero
  for(int i=0; i<n1; i++){
    for(int j=0; j<n3; j++){
      sum[i][j] = 0;
    }
  }

  // multiplying
  for(int i=0; i<n1; i++){
    for(int j=0; j<n3; j++){
      for(int k=0; k<n2; k++){
        sum[i][j] += a[i][k] * b[k][j];
      }
    }
  }


   for(int i=0; i<n1; i++){
    for(int j=0; j<n3; j++){
      cout<< sum[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}