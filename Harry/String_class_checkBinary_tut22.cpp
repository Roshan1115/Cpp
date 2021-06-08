#include<iostream>
using namespace std;
class binary{
  string s;
  bool check_binary();
  void compliment();
  void display();
  public:
    void read();  //need to declare it in public to be called by its object
};

void binary :: read(){
  cout<<"Enter the binary numver below\n";
  cin>>s;
  if(check_binary()){
    display();
    compliment();
    display();
  }
  else cout<<"The numver is not binary.\n";
}

bool binary :: check_binary(){
  for (int i = 0; i < s.length(); i++){
    if(s.at(i) != '0' && s.at(i) != '1') return false;
  }
  return true;
}

void binary :: compliment(){
  for (int i = 0; i < s.length(); i++){
    if(s.at(i) == '1') s.at(i) = '0';
    else if(s.at(i) == '0') s.at(i) = '1';
  }
  cout<<"Number is complimented.\n";
}

void binary :: display(){
  cout<<"The binary number is : "<<s<<endl;
}

int main(){
  binary obj;
  obj.read();
  return 0;
}