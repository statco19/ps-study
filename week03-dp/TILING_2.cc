#include <bits/stdc++.h>
#define ll long long

using namespace std;

int tc = 1;

int n;
int ar[101];
int mod = 1e9 + 7;

int tiling(int k) {  // 2 * k
	if(k <= 1) return 1;

	int& ret = ar[k];
	if(ret != -1) return ret;

	return ret = (tiling(k-1) + tiling(k-2)) % mod;
}

void sol() {
	cin >> n;
	memset(ar, -1, sizeof(ar));
	cout << tiling(n) << "\n";

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