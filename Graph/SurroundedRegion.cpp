#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

void change(vector<vector<char>> &a, int x, int y){
  a[x][y] = '*';
  int dx[] = {0,0,-1,1};  // don't know what is this
  int dy[] = {1,-1,0,0};

  rep(i,0,4){
    int cx = x + dx[i];
    int cy = y + dy[i];
    if(cx >=0 && cx < a.size() && cy >= 0 && cy < a.size() && a[cx][cy] == 'O')
      change(a,cx,cy);
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<char>> a(n,vector<char>(m));
  rep(i,0,n){
    rep(j,0,m)
      cin >> a[i][j];
  }
  rep(i,0,n){
    rep(j,0,m){
      if(i==0 || i==n-1 || j==0 || j==m-1)
        if(a[i][j] == 'O')
          change(a,i,j);  // convert to *
    }
  }
  rep(i,0,n){
    rep(j,0,m){
      if(a[i][j] == 'O')
        a[i][j] = 'X';
    }
  }
  rep(i,0,n){
    rep(j,0,m){
      if(a[i][j] == '*')
        a[i][j] = 'O';
    }
  }
  cout<< endl;
  // to display 
  rep(i,0,n){
    rep(j,0,m)
      cout<< a[i][j] << " ";
    cout<< endl;
  }


  

  return 0;
}

// use : g++ -std=c++11 

/*
input
4 4
X X X X
X O O X
X X O X
X O X X

output
X X X X 
X X X X 
X X X X 
X O X X 
*/