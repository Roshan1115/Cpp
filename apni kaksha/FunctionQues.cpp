#include<iostream>
#include<iomanip>
using namespace std;

void pyTriplet(int x, int y, int z){
  int a = max(x, max(y,z));
  int b,c;
  if(a == x) {b=y; c=z;}
  else if(a==y){ b=x; c=z;}
  else {b=x; c=y;}

  if(a*a == (b*b) + (c*c)){
    cout<<"Is is Pythagoras Triplet.\n";
  }
  else cout<<"It is not Pythagoras Triplet.\n";
}

void BinToDec(int n){
  int ans = 0, base = 1;  //base to power 0 is 1;
  while(n>0){
    int y = n%10;
    ans += base*y;
    base *= 2;
    n /=10;
  }
  cout<<"The decimal number is "<< ans<<endl;
}

void OctalToDec(int n){
  int ans = 0, base = 1;  //base to power 0 is 1;
  while(n>0){
    int y = n%10;
    ans += base*y;
    base *= 8;
    n /=10;
  }
  cout<<"The decimal number is "<< ans<<endl;
}

void hexadecToDec(string s){
  int ans = 0, base = 1;  //base to power 0 is 1;
  for(int i=(s.size()-1); i>=0; i--){
    if(s[i]>='0' && s[i]<='9')  ans += base*(s[i]-'0');
    else if(s[i]>='A' && s[i]<='F')  ans += base*(s[i]-'A'+10);
    base *= 16;  // base is 16 in hexadecemal
  }
  cout<<"The decemal number is "<< ans<< endl;
}

void DecToBinary(int n){
  int ans = 0, x = 1;
  while(x<=n)  x *= 2;
  x /= 2;   // for an extra multiplication, we devide once
  while(x>0){
    int lastDigit = n/x;
    n -= lastDigit*x;
    x /= 2;
    ans = ans*10 + lastDigit;
  }
  cout<<"The Binary Number is "<< ans<<endl;
}

void DecToOctal(int n){
  int ans = 0, x = 1;
  while(x<=n)  x *= 8;
  x /= 8;   // for an extra multiplication, we devide once
  while(x>0){
    int lastDigit = n/x;
    n -= lastDigit*x;
    x /= 8;
    ans = ans*10 + lastDigit;
  }
  cout<<"The Octal  Number is "<< ans<<endl;
}

void DecToHexaDec(int n){
  int x = 1;
  string ans = "";
  while(x<=n)  x *= 16;
  x /= 16; 
  while(x>0){
    int lastDigit = n/x;
    n -= lastDigit*x;
    x /= 16;
    if(lastDigit <=9)  ans += to_string(lastDigit);
    else{
      char c = 'A' + (lastDigit-10);
      ans.push_back(c);
    }
  }
  cout<<"The Hexa Decemal Number is "<< ans<<endl;
}

int reverse(int n){
    int answer = 0;
    while(n>0){
      int ld = n%10;
      answer = answer*10 + ld;
      n /= 10;
    }
    return answer;
}
void AddTwoBinary(int x, int y){
  int ans = 0, prevCarry = 0, count=0, count2=0;

  while(x>0 && y>0){
    int lastX = x%10;
    int lastY = y%10;

    if(lastX==0 && lastY==0){
      if(prevCarry==1) count2++;
      if(prevCarry==0) if(count2==0) count++;
      ans = ans*10 + prevCarry;
      prevCarry = 0;
    }
    else if( (lastX==0 && lastY==1) || (lastX==1 && lastY==0) ){
      if(prevCarry==0)  {
        ans= ans*10 + 1;
        count2++;
      }
      else if(prevCarry==1)  {
        ans= ans*10 + 0;
        if(count2==0) count++;
      }
    }
    else{
      if(prevCarry==1) count2++;
      if(prevCarry==0) if(count2==0) count++;
      ans = ans*10 + prevCarry;
      prevCarry = 1;
    }
    x /= 10;
    y /=10;
  }

  while(x>0){
    if(prevCarry==0){
      if(x%10 == 1) count2++;
      ans = ans*10 + (x%10);
      if(x%10==0 && count2==0) count++;
    }
    else if(prevCarry==1){
      if(x%10 == 0) {
        ans = ans*10 + 1;
        count2++;
        prevCarry = 0;
      }
      else {
        ans = ans*10 + 0;
        if(count2==0) count++;
      }
    }
    x /= 10;
  }
  while(y>0){
    if(prevCarry==0){
      if(y%10 == 1) count2++;
      ans = ans*10 + (y%10);
      if(y%10==0 && count2==0) count++;
    }
    else if(prevCarry==1){
      if(y%10 == 0) {
        ans = ans*10 + 1;
        count2++;
        prevCarry = 0;
      }
      else {
        ans = ans*10 + 0;
        if(count2==0) count++;
      }
    }
    y /= 10;
  }

  if(prevCarry == 1) ans = ans*10 + 1;
  ans = reverse(ans);
  cout<<"The sum is "<<ans;
  // cout << setw(count) << setfill('0') << joined << endl;
}

int main(){
  short int choice;
  bool i = true;
  int x,y,z;
  while(i){
    cout<<"Enter following\n"
        <<"1. for checking pythagoras triplet.\n"
        <<"2. for Binary to Decimal.\n"
        <<"3. For Octal to Decemal.\n"
        <<"4. For Hexadecemal to Decemal.\n"
        <<"5. For Decemal to Binary.\n"
        <<"6. For Decemal to Octal.\n"
        <<"7. For Decemal to Hexa Decemal.\n"
        <<"8. For adding two Binary Numbers.\n";
    cin>>choice;
    string s;
    switch (choice)
    {
    case 1:
      cout<<"Enter three number. ";
      cin>>x>>y>>z;
      pyTriplet(x,y,z);
      i = false;
      break;

    case 2:
      cout<<"Enter the Binary number. ";
      cin>>x;
      BinToDec(x);
      i = false;
      break;

    case 3:
      cout<<"Enter the Octal number. ";
      cin>>x;
      OctalToDec(x);
      i = false;
      break;

    case 4:
      cout<<"Enter the Hexadecemal Number. ";
      cin>>s;
      hexadecToDec(s);
      i = false;
      break;

    case 5:
      cout<<"Enter the Decemal Number. ";
      cin>>x;
      DecToBinary(x);
      i = false;
      break;

    case 6:
      cout<<"Enter the Decemal Number. ";
      cin>>x;
      DecToOctal(x);
      i = false;
      break;

    case 7:
      cout<<"Enter the Decemal Number. ";
      cin>>x;
      DecToHexaDec(x);
      i = false;
      break;

    case 8:
      cout<<"Enter two binary numbers. ";
      cin>>x>>y;
      AddTwoBinary(x,y);
      i = false;
      break;
    
    default:
      cout<<"Please enter from the given option only.\n";
      break;
    }
  }
  return 0;
}