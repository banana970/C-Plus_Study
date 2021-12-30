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

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};

vector<bool> isVisited;
void DFS(vector<vector<int>>& v, int start, int cur) {
	int next = -1;
	for (auto adj : v[cur]) {
		++next;
		if (adj == 0)
			continue;
		if (isVisited[next])
			continue;
		isVisited[next] = true;
		v[start][next] = 1;
		DFS(v, start, next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	for (int i = 0; i < N; i++) {
		isVisited.assign(N, false);
		DFS(v, i, i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << v[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}