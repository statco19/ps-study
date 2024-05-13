#include <bits/stdc++.h>

using namespace std;

int tc = 1;

int n,m;
bool isFriend[11][11];
int chosen;
int ans;

void check(int smallest, int pair) {
	if(pair == n/2) {
		ans++;
		return;
	}

	for(int i=0; i<n; ++i) {
		if(i < smallest) continue;
		if(chosen & (1<<i)) continue;
		for(int j=i+1; j<n; ++j) {
			if(chosen & (1<<j)) continue;
			if(isFriend[i][j] || isFriend[j][i]) {
				chosen ^= (1<<i);
				chosen ^= (1<<j);
				check(i, pair+1);
				chosen ^= (1<<i);
				chosen ^= (1<<j);
			}
		}
	}
}


void sol() {
	cin >> n >> m;
	chosen = 0;
	ans = 0;
	memset(isFriend, 0, sizeof(isFriend));
	int a,b;
	for(int i=0; i<m; ++i) {
		cin >> a >> b;
		isFriend[a][b] = isFriend[b][a] = true;
	}

	check(0,0);

	cout << ans << '\n';

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
