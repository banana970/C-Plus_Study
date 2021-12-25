//2670] 연속부분최대곱
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
double dp[10001];

int main(){
  freopen("input.txt","rt",stdin);
  int n;
  double num, res=0;
  
  scanf("%d",&n);
  vector<double> vt;

  //입력받은 자기 자신의 수로 초기화
  for(int i=0; i<n; i++){
    scanf("%lf", &dp[i]);
  }

  res=dp[0];
  for(int i=1; i<n; i++){
    //그 다음 수를 곱한 값이 더 크다면
    if(dp[i]<=dp[i]*dp[i-1]){
      dp[i]=dp[i]*dp[i-1];
    }
    res=max(res, dp[i]);

  }

  printf("%.3lf", res);
  return 0;
}
