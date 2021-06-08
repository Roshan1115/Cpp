#include<iostream>
using namespace std;

void reverseArray(int FNarr[],int start , int endpos){
    int temp;
    while(start < endpos){
        temp = FNarr[start];
        FNarr[start] = FNarr[endpos];
        FNarr[endpos] = temp;
        start++;
        endpos--;
    }   
}

int main(){
    // int arr[] = {1,2,3,4,5,6,7,8,9};
    int SIZE;
    cout<<"Enter the number of element there will be"<<endl;
    cin>>SIZE;
    cout<<"Enter elements"<<endl;
    int arr[SIZE], a=0;
    for (int i = 0; i < SIZE; i++){
        if(cin>>arr[i]){
            //Do nothing
        }
        else{
            break;
        }
    }
    
    int size = sizeof(arr)/sizeof(arr[0]) ;
    cout<<"The array before reversing is bellow"<<endl;
    for (int i = 0; i <size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverseArray(arr, 0, size-1);

    cout<<"The array after reversing is bellow"<<endl;
    for (int i = 0; i <size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}