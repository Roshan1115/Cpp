#include <iostream>
using namespace std;

class engine{
	public:
    	virtual void valv() = 0; 
    	virtual void carborator() = 0; 
};

class car: engine{
	public:
	void valv(){
    	cout<<"this is car's valv\n";
	}

	void carborator(){
    	cout<<"this is car's carborator\n";
	}
};

int main(){
	car ford;
	ford.valv();
	ford.carborator();
}