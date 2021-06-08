#include<iostream>
#include<string.h>
using namespace std;

class student{
  public:
  void getData(char fname[], int froll, int fmarks){
    strcpy(name, fname);
    roll = froll;
    marks = fmarks;
  }
  void showData(){
    cout<<"name is : "<<name<<endl;
    cout<<"roll is : "<<roll<<endl;
    cout<<"marks is : "<<marks<<endl;
    cout<<endl;
  }
  private:
  int roll, marks;
  char name[];
};

int main(){
  student s;
  student *ptr = &s;
  int roll, marks;
  char name[20];
  cout<<"Enter name : ";
  cin>>name;
  cout<<"Enter roll : ";
  cin>>roll;
  cout<<"Enter marks : ";
  cin>>marks;


  // pointer dereferencing 
  ptr->getData(name, roll, marks);
  ptr->showData();

  //Both the below lines are same executed as teh pointer methode
  // s.getData(name,rol,marks);
  // s.showData();

//another examle of pointer to class
student *p = new student;
p->getData("Manish", 45, 455);
p->showData();

  return 0;
}