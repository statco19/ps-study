#include <bits/stdc++.h>
#define ll long long

using namespace std;

int tc = 1;

const int INF = 0x3f3f3f3f;
int N,S;
int ar[101];
int psum[101], psqsum[101];
int cache[101][11];

int MSE(int s, int e) {  // [s,e]
	int mu = int(0.5 + (double)(psum[e] - psum[s-1]) / (e - s + 1));
	int ret = (psqsum[e] - psqsum[s-1]) - 2*mu*(psum[e] - psum[s-1]) + (e - s + 1)*pow(mu,2);

	return ret;
}

int quantize(int from, int parts) {
	if(from > N) return 0;
	if(parts == 0) return INF;

	int& ret = cache[from][parts];
	if(ret != INF) return ret;

	for(int i=1; i<=N-from+1; ++i) {
		ret = min(ret, MSE(from, from + i - 1) + quantize(from + i, parts - 1));
	}

	return ret;
}

void sol() {
	cin >> N >> S;
	memset(cache, INF, sizeof(cache));
	memset(ar, 0, sizeof(ar));
	memset(psum, 0, sizeof(psum));
	memset(psqsum, 0, sizeof(psqsum));

	for(int i=1; i<=N; ++i) {
		cin >> ar[i];
	}
	sort(ar, ar+N+1);

	for(int i=1; i<=N; ++i) {
		psum[i] = ar[i] + psum[i-1];
		psqsum[i] = pow(ar[i],2) + psqsum[i-1];
	}

	cout << quantize(1, S) << "\n";

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