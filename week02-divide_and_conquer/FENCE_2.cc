#include <bits/stdc++.h>

using namespace std;

int tc = 1;

int N;
vector<int> h;

int getMax(int l, int r) {  // [l,r)
	if(r-l == 1) {
		return h[l];
	}
	if(l >= r) return 0;

	int mid = (l+r)/2;
	int lo = mid-1, hi = mid;

	int height = min(h[lo], h[hi]);
	int ret = (hi-lo+1) * height;

	// short-circuit evaluation
	while(l < lo || hi < r-1) {
		if(l < lo && (hi == r-1 || h[lo-1] > h[hi+1])) {
			--lo;
			height = min(h[lo], height);
		} else {
			++hi;
			height = min(h[hi], height);
		}

		ret = max(ret, (hi-lo+1) * height);
	}

	return max(ret, max(getMax(l, mid), getMax(mid, r)));
}

void sol() {
	cin >> N;
	h.resize(N);
	for(int& x : h) cin >> x;

	int ans = getMax(0,N);
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
