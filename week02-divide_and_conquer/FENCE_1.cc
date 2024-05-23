#include <bits/stdc++.h>

using namespace std;

int tc = 1;

int N;
int maxArea;
vector<int> ar;

int getMinHeightIdx(int l, int r) {  // [l, r)
	int ret = 0x3f3f3f3f;
	if(r < l) swap(l,r);
	int idx = l;

	for(int i=l; i<r; ++i) {
		if(ar[i] < ret) {
			ret = min(ar[i], ret);
			idx = i;
		}
	}

	return idx;
}

int getMax(int l, int r) {  // [l, r)
	if(r < l) swap(l,r);
	if(l >= r) return 0;

	int idx = getMinHeightIdx(l,r);
	int tmpArea = ar[idx] * abs(r-l);
	maxArea = max(maxArea, tmpArea);

	int leftArea = getMax(l, idx);
	int rightArea = getMax(idx+1, r);

	return max(maxArea, max(leftArea, rightArea));
}

void sol() {
	maxArea = 0;
	cin >> N;
	ar.resize(N);
	for(int& x : ar) cin >> x;

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
