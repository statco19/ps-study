#include <bits/stdc++.h>

using namespace std;

int tc = 1;

int N;
vector<int> ar;
int cache[501];

int lis(int idx) {
	int& ret = cache[idx];
	if(ret != -1) return ret;

	ret = 1;  // the minimum length is 1
	for(int i=idx+1; i<N; ++i) {
		if(ar[idx] < ar[i]) {
			ret = max(ret, 1 + lis(i));
		}
	}

	return ret;
}

void sol() {
	cin >> N;
	memset(cache, -1, sizeof(cache));
	ar.resize(N);
	for(int& x : ar) cin >> x;

	int ans = 0;
	for(int i=0; i<N; ++i) {
		ans = max(ans, lis(i));
	}
	cout << ans << "\n";

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