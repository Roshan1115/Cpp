#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a[3][3],b[3][3],c[3][3],i,j,k;
    cout<<"Enter the elements for first Arrya :\n";
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cin>>a[i][j];
        }
    }
cout<<"Enter the elements of second Array : \n";
for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cin>>b[i][j];
        }
    }
cout<<endl<<"The product of both matrices are : \n ";
for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
                c[i][j]= c[i][j] + a[i][k]*b[k][j];
            }
        }
    }
for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cout<<c[i][j]<<" ";
            if(j==2){
                cout<<endl;
            }
        }
    }
    cout<<"\n";
    return 0;
}