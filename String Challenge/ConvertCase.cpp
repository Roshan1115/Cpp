// #include<iostream>
// using namespace std;

// int main(){
//   string s;
//   cin>>s;
  
//   // converting to upper case
//   for(int i=0; i<s.size(); i++){
//     if(s[i] >= 'a' && s[i] <= 'z'){
//       s[i] -= 32;   // small charracter is 32 unit after the capital letter
//     }
//   }
//   cout<< s<< endl;


//   // converting to lower case
//   for(int i=0; i<s.size(); i++){
//     if(s[i] >= 'A' && s[i] <= 'Z'){
//       s[i] += 32;   // small charracter is 32 unit after the capital letter
//     }
//   }
//   cout<< s<< endl;

//   return 0;
// }


// better approach
#include<iostream>
// #include<string>
using namespace std;

int main(){
  string s;
  cin>> s;

  transform(s.begin(), s.end(), s.begin(), ::toupper);
  cout<< s<<endl;

  transform(s.begin(), s.end(), s.begin(), ::tolower);
  cout<< s;
  return 0;
}