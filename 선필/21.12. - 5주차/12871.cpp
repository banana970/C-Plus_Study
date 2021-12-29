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

	string a, b, c = "", d = "";
	cin >> a >> b;
	
	int l = lcm(a.size(), b.size()); // c++17 <numeric> 유클리드 호제법 O(logN)
	for (int i = 0; i < l / a.size(); i++)
		c += a;
	for (int i = 0; i < l / b.size(); i++)
		d += b;

	cout << (c == d ? 1 : 0);

	return 0;
}