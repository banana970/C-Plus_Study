#include <iostream>

using namespace std;

bool visited[251][251]; // 방문했던 곳인지 아닌지 판별
string map[251]; // 목장 map
int v = 0, k = 0, R, C;

// 한 울타리 안에 v와 k의 개수를 count하는 dfs 함수
void checking(int r, int c) {

	if (visited[r][c] == true) return; // 방문했던 곳은 또 방문하지 않고 넘어감
	if (r >= R || c >= C) return; // 목장의 크기만큼만 탐색
	
  visited[r][c] = true; // 방문했음을 표시

  // 각 위치에 따른 동작
	if (map[r][c] == '#') return; 
	else if (map[r][c] == 'v') v++; 
	else if (map[r][c] == 'k') k++;

  // 상하좌우 탐색
	checking(r, c + 1);
	checking(r + 1, c);
	if (c != 0) checking(r, c - 1);
	if (r != 0) checking(r - 1, c);

	return;
}

int main(void) {

	int sheep = 0, wolf = 0;
	
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

  // 모든 위치 탐색
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == true) continue; // 방문했던 곳은 넘어감
			v = 0; k = 0;
			checking(i, j);
      
      // 한 울타리 안에 양의 수가 더 많다면 양의 수 증가, 아니라면 늑대의 수 증가
			if (v < k) sheep += k; 
			else wolf += v;
		}
	}

	cout << sheep << " " << wolf;
}
