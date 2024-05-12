#include <bits/stdc++.h>

using namespace std;

int T = 1;

int N;
vector<int> v;
int ans;

void sol() {
	cin >> N;
	v.resize(N);
	for(int& x : v) cin >> x;

	sort(v.begin(), v.end());
	while(next_permutation(v.begin(), v.end())) {
		int sum = 0;
		for(int i=0; i<(int)v.size()-1; ++i) {
			sum += abs(v[i+1] - v[i]);
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for(int i=1; i<=T; ++i) {
		sol();
	}

	return 0;
}
