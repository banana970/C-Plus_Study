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

	vector<vector<char>> v(N, vector<char>(M));
	vector<vector<bool>> isVisited(N, vector<bool>(M));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> v[i][j];
	
	vector<int> ans(2);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isVisited[i][j] || v[i][j] == '#')
				continue;

			int sheep = 0, wolves = 0;
			isVisited[i][j] = true;
			queue<pair<int, int>> q;
			q.emplace(i, j);

			while (!q.empty()) {
				int row = q.front().first;
				int col = q.front().second;
				q.pop();

				if (v[row][col] == 'v')
					wolves++;
				else if (v[row][col] == 'k')
					sheep++;

				for (int dir = 0; dir < 4; dir++) {
					int nextRow = row + dr[dir];
					int nextCol = col + dc[dir];

					if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= M)
						continue;
					if (isVisited[nextRow][nextCol] || v[nextRow][nextCol] == '#')
						continue;

					isVisited[nextRow][nextCol] = true;
					q.emplace(nextRow, nextCol);
				}
			}

			if (sheep > wolves)
				ans[0] += sheep;
			else
				ans[1] += wolves;
		}
	}

	cout << ans[0] << ' ' << ans[1];

	return 0;
}