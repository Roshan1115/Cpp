#include<iostream>
#include<vector>
using namespace std;

class test{

  public:
  int x;
  test* next;

  test(){
    next = NULL;
  }
};

vector<int> arr = {1,2,3,4};

test* build(){
  test obj;
  test* root = &obj;
  test* head = root;
  for(int i=0;i<arr.size(); i++){
    head->x = arr[i];
    if(i != arr.size()-1)
    {
      test obj2;
      head->next =  &obj2;
      head = head->next;
    }
  }
  
  // test* root2 = root;
  // while(root2 != NULL){
  //   cout<< root2->x<<" ";
  //   root2 = root2->next;
  // }cout<<endl;


  return root;
}

int main(){
  
  test* given = build();

  cout<<endl;
  while(given != NULL){
    cout<<"HELLO ";
    cout<< given->x<<" ";
    given = given->next;
  }cout<<endl;

  return 0;
  }

// use : g++ -std=c++11 