#include <bits/stdc++.h>
#define ll long long

using namespace std;

int tc = 1;
const int mINF = 0xc0c0c0c0;
int N;
int ar[501];
int cache[501];

int lis(int index) {
	int& ret = cache[index+1];
	if(ret != -1) return ret;

	ret = 1;
	int num = (index == -1 ? mINF : ar[index]);
	for(int next = index + 1; next < N; ++next) {
		if(num < ar[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}

	return ret;
}

void sol() {
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<N; ++i) {
		cin >> ar[i];
	}

	cout << lis(-1) - 1 << "\n";

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