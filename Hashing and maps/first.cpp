/*
two maps are there
1 map in <map>
2 unordered_map in <unordered_map>
*/

#include<iostream>
#include<map>
using namespace std;

int main(){
  
  // declaring map : map<key_datatype, value_datatype> name;
  map<int, int> m;

  m[7] = 20;
  cout<< m[7]<< endl;

  for(map<int, int>:: iterator it = m.begin(); it != m.end(); it++)
    cout<< it->first<<" : "<<it->second<< endl;
  cout<< endl;

  return 0;
}