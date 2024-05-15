#include <bits/stdc++.h>

using namespace std;

int tc = 1;

char bd[21][21];
int H,W;
int ans;
int space;

bool fit(int r, int c, int type) {
	if(type == 0) {
		if(r<0 || r+1>=H || c<0 || c+1>=W) return false;
		if(bd[r][c] == '#' || bd[r][c+1] == '#' || bd[r+1][c+1] == '#') return false;

		return true;
	}
	else if(type == 1) {
		if(r<0 || r+1>=H || c-1<0 || c>=W) return false;
		if(bd[r][c] == '#' || bd[r+1][c] == '#' || bd[r+1][c-1] == '#') return false;

		return true;
	}
	else if(type == 2) {
		if(r<0 || r+1>=H || c<0 || c+1>=W) return false;
		if(bd[r][c] == '#' || bd[r+1][c] == '#' || bd[r+1][c+1] == '#') return false;

		return true;
	}
	else {
		if(r<0 || r+1>=H || c<0 || c+1>=W) return false;
		if(bd[r][c] == '#' || bd[r][c+1] == '#' || bd[r+1][c] == '#') return false;

		return true;
	}
}

void addBlock(int r, int c, int t) {
	if(t == 0) {
		bd[r][c] = bd[r][c+1] = bd[r+1][c+1] = '#';
	} else if(t == 1) {
		bd[r][c] = bd[r+1][c] = bd[r+1][c-1] = '#';
	} else if(t == 2) {
		bd[r][c] = bd[r+1][c] = bd[r+1][c+1] = '#';
	} else {
		bd[r][c] = bd[r][c+1] = bd[r+1][c] = '#';
	}
}

void removeBlock(int r, int c, int t) {
	if(t == 0) {
		bd[r][c] = bd[r][c+1] = bd[r+1][c+1] = '.';
	} else if(t == 1) {
		bd[r][c] = bd[r+1][c] = bd[r+1][c-1] = '.';
	} else if(t == 2) {
		bd[r][c] = bd[r+1][c] = bd[r+1][c+1] = '.';
	} else {
		bd[r][c] = bd[r][c+1] = bd[r+1][c] = '.';
	}
}

void cover(int remain) {
	if(remain == 0) {
		ans++;
		return;
	}

	int r,c;
	bool found = 0;
	for(int i=0; i<H; ++i) {
		for(int j=0; j<W; ++j) {
			if(bd[i][j] == '.') {
				r = i;
				c = j;
				found = true;
				break;
			}
		}
		if(found) break;
	}

	for(int t=0; t<4; ++t) {
		if(fit(r,c,t)) {
			addBlock(r,c,t);
			cover(remain-3);
			removeBlock(r,c,t);
		}
	}

	return;
}

void sol() {
	ans = 0;
	space = 0;
	cin >> H >> W;
	for(int i=0; i<H; ++i) {
		for(int j=0; j<W; ++j) {
			cin >> bd[i][j];
			if(bd[i][j] == '.') space++;
		}
	}

	if(space % 3) {
		cout << 0 << '\n';
		return;
	}

	cover(space);
	cout << ans << '\n';

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
