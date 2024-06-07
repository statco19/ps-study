#include <bits/stdc++.h>
#define ll long long

using namespace std;

int tc = 1;

const int INF = 0x3f3f3f3f;
string s;
int cache[10001];

int cal(const string& num, int len) {
	bool case1 = true;
	for(int i=0; i<len-1; ++i) {
		if(num[i] != num[i+1]) {
			case1 = false;
			break;
		}
	}
	if(case1) return 1;

	bool case2 = true;
	for(int i=0; i<len-1; ++i) {
		if(num[i+1] - num[i] != 1) {
			case2 = false;
			break;
		}
	}
	if(case2) return 2;
	case2 = true;
	for(int i=0; i<len-1; ++i) {
		if(num[i] - num[i+1] != 1) {
			case2 = false;
			break;
		}
	}
	if(case2) return 2;

	bool case3 = true;
	for(int i=0; i<len-2; ++i) {
		if(num[i] != num[i+2]) {
			case3 = false;
			break;
		}
	}
	if(case3) return 4;

	bool case4 = true;
	for(int i=0; i<len-2; ++i) {
		if(num[i+1]-num[i] != num[i+2]-num[i+1]) {
			case4 = false;
			break;
		}
	}
	if(case4) return 5;

	return 10;
}

int pi(const string& num, int x) {
	if(x == 0) return 0;
	if(x < 3) return INF;

	int& ret = cache[x];
	if(ret != INF) return ret;

	if(x >= 3) {
		ret = min(ret, cal(num.substr(0,3), 3) + pi(num.substr(3), x-3));
	}
	if(x >= 4) {
		ret = min(ret, cal(num.substr(0,4), 4) + pi(num.substr(4), x-4));
	}
	if(x >= 5) {
		ret = min(ret, cal(num.substr(0,5), 5) + pi(num.substr(5), x-5));
	}

	return ret;
}

void sol() {
	cin >> s;
	memset(cache, INF, sizeof(cache));
	cout << pi(s, (int)s.size()) << "\n";	

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