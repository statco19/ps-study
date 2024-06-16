#include <bits/stdc++.h>
#define ll long long

using namespace std;

int tc = 1;

int n;
int tri[101][101];
int paths[101][101];

int cache[101][101];
int mx;
int cnt;

int maxValue(int r, int c) {
	if(r == n-1) {
		paths[r][c] = 1;
		return tri[r][c];
	}

	int& ret = cache[r][c];
	if(ret != -1) {
		return ret;
	}

	int v1 = maxValue(r+1,c);
	int v2 = maxValue(r+1,c+1);

	if(v1 > v2) {
		ret = tri[r][c] + v1;
		paths[r][c] += paths[r+1][c];
	} else if(v1 < v2) {
		ret = tri[r][c] + v2;
		paths[r][c] += paths[r+1][c+1];
	} else {
		ret = tri[r][c] + v1;
		paths[r][c] += paths[r+1][c] + paths[r+1][c+1];
	}

	return ret;
}

void sol() {
	cin >> n;
	mx = cnt = 0;
	memset(tri, 0, sizeof(tri));
	memset(paths, 0, sizeof(paths));
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<i+1; ++j) {
			cin >> tri[i][j];
		}
	}

	maxValue(0,0);
	cout << paths[0][0] << "\n";

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