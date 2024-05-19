#include <bits/stdc++.h>

using namespace std;

int tc = 1;

int H,W;
int bd[21][21];
int space;
// dx,dy 방식으로 블럭 타입을 구현
const int coverType[4][3][2] = {
	{ {0,0},{0,1},{1,0} },
	{ {0,0},{0,1},{1,1} },
	{ {0,0},{1,0},{1,1} },
	{ {0,0},{1,0},{1,-1} }
};

bool setBlock(int r, int c, int t, int delta) {
	bool ret = true;
	for(int i=0; i<3; ++i) {
		const int nr = r + coverType[t][i][0];
		const int nc = c + coverType[t][i][1];

		if(nr<0 || nr >=H || nc<0 || nc>=W) ret = false;
		else if((bd[nr][nc] += delta) > 1) ret = false;
	}

	return ret;
}

int cover() {
	int r = -1, c = -1;
	for(int i=0; i<H; ++i) {
		for(int j=0; j<W; ++j) {
			if(bd[i][j] == 0) {
				r = i; c = j;
				break;
			}
		}
		if(r != -1) break;
	}

	if(r == -1) return 1;  // 빈 칸이 없을 때, 즉 모든 칸을 채웠으면 1 반환

	int ret = 0;
	// setBlock으로 블럭을 놓을 수 있는지 체크 + 블럭 놓기/제거하기
	for(int t=0; t<4; ++t) {
		if(setBlock(r,c,t,1)) {
			ret += cover();
		}
		setBlock(r,c,t,-1);
	}

	return ret;
}

void sol() {
	space = 0;
	cin >> H >> W;
	char ch;

	for(int i=0; i<H; ++i) {
		for(int j=0; j<W; ++j) {
			cin >> ch;
			if(ch == '#') bd[i][j] = 1;
			else {
				space++;
				bd[i][j] = 0;
			}
		}
	}

	if(space % 3 == 0) cout << cover() << "\n";
	else cout << 0 << "\n";

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
