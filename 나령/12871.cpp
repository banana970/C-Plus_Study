//12871] 무한 문자열
#include<iostream>
using namespace std;

//최대공약수
int GCD(int a, int b){
  int c;
  while(b!=0){
    c=a%b;
    a=b;
    b=c;
  }
  return a;
}

//최소공배수
int LCM(int a, int b){
  return a*b / GCD(a, b);
}

int main(){
  //freopen("input.txt","rt",stdin);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s, t, fs, ft;
  cin>>s>>t;
  int tmp=LCM(s.length(), t.length());

  for(int i=0; i<tmp/s.length(); i++){
    fs+=s;
  }
  for(int j=0; j<tmp/t.length(); j++){
    ft+=t;
  }

  if(fs==ft) cout<<"1";
  else cout<<"0";
  return 0;
}