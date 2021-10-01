#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

bool haveCommon(string &a, string &b){
        vector<int> charactors(256, 0);
        for(int i=0; i< a.length(); i++){
            charactors[a[i]]++;
        }
        for(int i=0; i< b.length(); i++){
            if(charactors[b[i]]){
                return true;
            }
        }
        return false;
    }

int main(){
    string i = "Roshan";
    int l =  i.length();
    cout<< max(4, (int)i.length())<< endl;
  return 0;
}

// use : g++ -std=c++11 