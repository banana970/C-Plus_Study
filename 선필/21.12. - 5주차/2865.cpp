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

	int N, M, K;
	cin >> N >> M >> K;

	priority_queue<pair<double, int>> pq;
	for (int i = 0; i < N * M; i++) {
		int person;
		double ability;
		cin >> person >> ability;
		pq.emplace(ability, person);
	}

	vector<bool> isSelected(N + 1);
	double ans = 0;
	while (K--) {
		while (isSelected[pq.top().second])
			pq.pop();
		isSelected[pq.top().second] = true;
		ans += pq.top().first;
	}

	cout.precision(1);
	cout << fixed << ans;

	return 0;
}