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

void DFS(const int& R, const int& C, vector<vector<int>>& dp, int row, int col, int cost) {
	for (int i = 0; i < 4; i++) {
		int nextRow = row + dr[i];
		int nextCol = col + dc[i];

		if (nextRow < 0 || nextCol < 0 || nextRow > R || nextCol > C)
			continue;

		if ((nextRow == 0 || nextRow == R) || (nextCol == 0 || nextCol == C)) {
			if (cost + 1 >= dp[nextRow][nextCol])
				continue;

			dp[nextRow][nextCol] = cost + 1;
			DFS(R, C, dp, nextRow, nextCol, cost + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, C;
	cin >> C >> R;
	vector<vector<int>> dp(R + 1, vector<int>(C + 1, INF));

	int N;
	cin >> N;
	vector<pair<int, int>> shops(N);
	for (int i = 0; i < N; i++) {
		int dir, dist;
		cin >> dir >> dist;

		if (dir == 1)
			shops[i] = {0, dist};
		else if (dir == 2)
			shops[i] = {R, dist};
		else if (dir == 3)
			shops[i] = {dist, 0};
		else if (dir == 4)
			shops[i] = {dist, C};
	}

	int dir, dist;
	cin >> dir >> dist;

	int r, c;
	if (dir == 1)
		r = 0, c = dist;
	else if (dir == 2)
		r = R, c = dist;
	else if (dir == 3)
		r = dist, c = 0;
	else if (dir == 4)
		r = dist, c = C;
	dp[r][c] = 0;
	DFS(R, C, dp, r, c, 0);

	int ans = 0;
	for (auto shop : shops)
		ans += dp[shop.first][shop.second];
	cout << ans;

	return 0;
}