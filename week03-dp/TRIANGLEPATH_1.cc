#include <bits/stdc++.h>

using namespace std;

int tc = 1;
int triangle[101][101];
int cache[101][101];
int n;

int path(int y, int x) {
	if(y>=n || x >=n) return 0;
	if(y == n-1) return triangle[y][x];

	int& ret = cache[y][x];
	if(ret != -1) return ret;

	return ret = (triangle[y][x] + max(path(y+1, x), path(y+1, x+1)));
}

void sol() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<i+1; ++j) {
			cin >> triangle[i][j];
		}
	}

	cout << path(0,0) << "\n";

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