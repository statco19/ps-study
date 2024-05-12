#include <bits/stdc++.h>

using namespace std;

int T = 1;

int N;
vector<int> v,picked;
bool chosen[9];
int ans = 0;

void recursion(int n, vector<int>& p) {
	if((int)p.size() == n) {
		int sum = 0;
		for(int i=0; i<n-1; ++i) {
			sum += abs(p[i+1] - p[i]);
		}
		ans = sum > ans ? sum : ans;
		return;
	}

	for(int i=0; i<n; ++i) {
		if(!chosen[i]) {
			p.push_back(v[i]);
			chosen[i] = true;
			recursion(n, p);
			chosen[i] = false;
			p.pop_back();
		}
	}
	return;
}

void sol() {
	ans = 0;
	cin >> N;
	v.resize(N);
	for(int& x : v) cin >> x;

	recursion(N, picked);

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for(int i=1; i<=T; ++i) {
		sol();
		cout << ans << '\n';
	}

	return 0;
}
