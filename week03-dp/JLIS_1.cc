#include <bits/stdc++.h>
#define ll long long

using namespace std;

int tc = 1;

const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int n,m;
vector<int> A,B;
int cache[101][101];

int JLIS(int indexA, int indexB) {
	int& ret = cache[indexA+1][indexB+1];
	if(ret != -1) return ret;

	ret = 2;
	ll a = (indexA == -1 ? mLINF : A[indexA]);
	ll b = (indexB == -1 ? mLINF : B[indexB]);
	ll maxElement = max(a,b);

	for(int nextA = indexA + 1; nextA < n; ++nextA) {
		if(maxElement < A[nextA]) {
			ret = max(ret, JLIS(nextA, indexB) + 1);
		}
	}
	for(int nextB = indexB + 1; nextB < m; ++nextB) {
		if(maxElement < B[nextB]) {
			ret = max(ret, JLIS(indexA, nextB) + 1);
		}
	}

	return ret;
}

void sol() {
	cin >> n >> m;
	A.clear(); B.clear();
	memset(cache, -1, sizeof(cache));
	
	int x;
	for(int i=0; i<n; ++i) {
		cin >> x;
		A.push_back(x);
	}
	for(int i=0; i<m; ++i) {
		cin >> x;
		B.push_back(x);
	}

	cout << JLIS(-1,-1) - 2 << "\n";

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