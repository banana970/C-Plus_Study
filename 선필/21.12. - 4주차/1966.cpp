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

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		priority_queue<int> prio;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			q.emplace(n, i), prio.push(n);
		}

		int ans = 1;
		while (true) {
			if (q.front().first < prio.top())
				q.emplace(q.front()), q.pop();
			else if (q.front().second == M)
				break;
			else
				q.pop(), prio.pop(), ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}