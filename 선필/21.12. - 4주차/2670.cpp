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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<double> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	double ans = 0;

	for (int i = 0; i < N; i++) {
		double cur = 1;
		for (int j = i; j < N; j++) {
			cur *= v[j];
			ans = max(ans, cur);
		}
	}

	cout.precision(3);
	cout << fixed << ans;

	return 0;
}