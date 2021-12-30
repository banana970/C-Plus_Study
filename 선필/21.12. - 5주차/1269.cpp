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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<int, int> A, B;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		A[n]++;
	}
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		B[n]++;
	}

	int ans = 0;
	for (auto a : A) {
		if (B[a.first] == 0)
			ans++;
	}
	for (auto b : B) {
		if (A[b.first] == 0)
			ans++;
	}

	cout << ans;
	
	return 0;
}