#include<iostream>
#include<vector>
using namespace std;

int main(){
    int input;
    vector<int> a;
    for (int i = 1; i <= 5; i++){
        // cin>>input;
        a.push_back(i);
    }
    cout<<"The array is "<<endl;
    for(auto i = a.begin(); i != a.end(); i++){
        cout<< *i<<"  ";
    }

    return 0;
}