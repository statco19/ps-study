#include <bits/stdc++.h>

using namespace std;

int tc = 1;

int n;
int bd[101][101];
int cache[101][101];

bool jump(int y, int x) {
	if(y >= n || x >= n) return false;
	if(y == n-1 && x == n-1) return true;

	int jumpSize = bd[y][x];
	return jump(y+jumpSize, x) || jump(y, x+jumpSize);
}

int jump2(int y, int x) {
	if(y >= n || x >= n) return false;
	if(y == n-1 && x == n-1) return true;

	int& ret = cache[y][x];
	if(ret != -1) return ret;

	int jumpSize = bd[y][x];
	return ret = jump2(y+jumpSize, x) || jump2(y, x+jumpSize);
}

void sol() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> bd[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
	if(jump2(0,0))
		cout << "YES\n";
	else
		cout << "NO\n";

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> tc;
	for(int i=1; i<=tc; ++i) {
		sol();
	}

	return 0;
}
