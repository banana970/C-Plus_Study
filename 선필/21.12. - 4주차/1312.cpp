#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <cctype>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

/*
* std:cout 기본 정밀도: 6
* std:setprecision(n) 으로 정밀도 override 가능
* float 정밀도: 6 ~ 9
* double 정밀도: 15 ~ 18
* 따라서, 한 번의 나눗셈으로는 정확한 소수점 아래 1,000,000 번째 자리의 값을 구할 수 없다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, N;
	cin >> A >> B >> N;

	if (A % B == 0) // 나누어 떨어지는 경우
		cout << 0;
	else { // 직접 손으로 나눗셈 계산하는 방식
		if (A > B) // A가 큰 경우, B로 나눈 몫은 소숫점 이상이므로 나눗셈 1회 진행
			A %= B;

		int res = 0;
		for (int i = 0; i < N; i++) {
			A *= 10; //  현재 나머지(A)의 자릿수를 하나 올린 후 나누어 떨어진 몫으로, 소수점 이하 i번째 자리를 구하기 위함
			res = A / B; // 소수점 이하 i번째 자리
			A %= B; // 나눗셈 진행
		}

		cout << res;
	}

	return 0;
}