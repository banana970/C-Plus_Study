//1312] 소수
//float,double type은 부동소수점이라 자릿수가 커질수록 정확도 떨어짐
#include<iostream>
using namespace std;

int main(){
  //freopen("input.txt","rt",stdin);
  int a, b, n, ans;
  scanf("%d %d %d", &a, &b, &n);

  while(n--){
    a=a%b;
    a*=10;
    ans=a/b;
  }

  printf("%d", ans);
  return 0;
}

