#include<iostream>
#include<stdlib.h>
using namespace std;

class myArray{
  int total_size,used_size;
  int *ptr;

  public:
      myArray(myArray *arr, int tsize, int usize){
      arr->total_size = tsize;
      arr->used_size = usize;
      arr->ptr = (int *) malloc(tsize * sizeof(int));   //reserve memory for arry of given size in heap not in stack.

      // cout<<arr->total_size<<endl;
      // cout<<arr->used_size<<endl;
      // cout<<arr->ptr<<endl;
      // cout<<arr<<endl;
    }
    void show(myArray *a){
      cout<<"The numbers are \n";
      for(int i = 0; i< a->used_size; i++){
        cout<<a->ptr[i]<<endl;
      }
    }

    void input(myArray *a){
      cout<<"Enter values \n";
      for(int i = 0; i< a->used_size; i++){
        cin>>a->ptr[i];
      }
    }
};

int main(){

  int tsize,usize;
  cout<<"Enter total size and used size\n";
  cin>>tsize>>usize;

  myArray obj(&obj, tsize, usize);
  obj.input(&obj);
  obj.show(&obj);

  // cout<< &obj;
  // createArr(&obj, 100, 25);
  return 0;
}