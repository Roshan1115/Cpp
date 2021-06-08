#include<iostream>
using namespace std;

class Friend {
  int id;
  static int count;
  public:
    void get(){
    cout<<"Enter id \n";
    cin>>id;
    count++;
    }
    void show(){
    cout<<"Friend id is "<<id<<endl;
    }
    static void totalMembers(){
      cout<<"Total members are "<<count<<endl;
    }
};
 
int Friend :: count;        // Default is zero we can set to any number by writting "int friend :: count = 2000"

int main(){
  Friend Roshan, Manish, Bittu,obj;
  Roshan.get();
  Manish.get();
  Bittu.get();

  Roshan.show();
  Manish.show();
  Bittu.show();

  Friend :: totalMembers();
  return 0;
}