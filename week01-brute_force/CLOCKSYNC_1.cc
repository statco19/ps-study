#include <bits/stdc++.h>

using namespace std;

int tc = 1;

vector<vector<int>> switches = {
	{0,1,2}, {3,7,9,11}, {4,10,14,15}, {0,4,5,6,7}, {6,7,8,10,12},
	{0,2,14,15}, {3,14,15}, {4,5,7,14,15}, {1,2,3,4,5}, {3,4,5,9,13}
};
int clocks[16];
int ans;
int cnt;

void push(int rep, vector<int>& v) {
	for(int& x : v) {
		for(int i=0; i<rep; ++i) {
			clocks[x] += 3;
		}
	}
	cnt += rep;
	return;
}

void undo(int rep, vector<int>& v) {
	for(int& x : v) {
		for(int i=0; i<rep; ++i) {
			clocks[x] -= 3;
		}
	}
	cnt -= rep;
	return;
}


void dfs(int depth) {
	if(depth == 10) {
		bool okay = true;
		for(int i=0; i<16; ++i) {
			if(clocks[i] % 12) {
				okay = false;
				break;
			}
		}

		if(okay) {
			ans = cnt < ans ? cnt : ans;
		} 
		
		return;
	}

	vector<int> v = switches[depth];
	for(int rep=0; rep<4; ++rep) {
		push(rep, v);
		dfs(depth+1);
		undo(rep, v);
	}
	return;
}

void sol() {
	ans = 0x3f3f3f3f;
	cnt = 0;
	for(int i=0; i<16; ++i) {
		cin >> clocks[i];
	}

	dfs(0);

	if(ans == 0x3f3f3f3f) ans = -1;

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
