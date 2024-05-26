// TLE code
#include <bits/stdc++.h>

using namespace std;

int tc = 1;
string member,fan;
int ans;

bool count(int l, int r, int st) {
	if(l+1 == r) {
		if(member[l-st] == 'M' && fan[l] == 'M') {
			return false;
		} else {
			return true;
		}
	}

	int mid = (l+r)/2;
	return count(l,mid,st) && count(mid,r,st);
}

void sol() {
	cin >> member >> fan;
	ans = 0;
	for(int i=0; i<=(int)(fan.size()-member.size()); ++i) {
		int start = i;
		if(count(i, i+(int)member.size(), start)){
			ans++;
		}
	}

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
