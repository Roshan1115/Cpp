/*
1 is safe to go and 0 is not safe to go for rat.
The rat is at point (0,0) initially and have to go to final point
(n-1,n-1). this is a square matrix.
x is rows
y is colums

1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/


#include<iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
  if(x<n && y<n && arr[x][y] == 1){
    return true;
  }
  return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr){
  
  if(x==n-1 && y==n-1){   // base case
    solArr[x][y] = 1;
    return true;
  }

  if(isSafe(arr, x, y, n)){
    solArr[x][y] = 1;

    if(ratInMaze(arr, x+1, y, n, solArr)){  // going down
      return true;
    }
    if(ratInMaze(arr, x, y+1, n, solArr)){  // going right
      return true;
    }
    solArr[x][y] = 0;   // backtracking
    return false;

  }
  return false;
}

int main(){
  int n;
  cout<<"Enter size of the square matrix : ";
  cin>>n;
  cout<<"Enter the path\n";

  int **arr = new int *[n];   //initialising first array in dynaic way
  for(int i=0; i<n; i++){
    arr[i] = new int[n];
    for(int j=0; j<n; j++){
      cin>> arr[i][j];
    }
  }

  cout<< endl;

  int **solArr = new int *[n];
  for(int i=0; i<n; i++){
    solArr[i] = new int [n];
    for(int j=0; j<n; j++){
      solArr[i][j] = 0;
    }
  }

  if(ratInMaze(arr, 0, 0, n, solArr)){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cout<< solArr[i][j]<< " ";
      }
      cout<< endl;
    }
  }
  return 0;
}