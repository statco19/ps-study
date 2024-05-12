#include <bits/stdc++.h>

using namespace std;

int tc = 1;

char bd[6][6];
string word;
const int d8r[8] = {-1,-1,-1,0,0,1,1,1}; const int d8c[8] = {-1,0,1,-1,1,-1,0,1};

bool hasWord(int r, int c, const string& word) {
	// for문 앞에서 범위 체크, 첫 글자 체크, 한글자 여부 체크
	if(r < 0 || r >=5 || c < 0 || c >=5) return false;
	if(word[0] != bd[r][c]) return false;
	if(word.size() == 1) return true;

	for(int d=0; d<8; ++d) {
		// for문 안에서 기저 사례 체크할 필요 없어짐
		int nr = r + d8r[d];
		int nc = c + d8c[d];

		if(hasWord(nr,nc, word.substr(1))) {
			return true;
		}
	}
	return false;
}

void sol() {
	for(int i=0; i<5; ++i) {
		for(int j=0; j<5; ++j) {
			if(hasWord(i,j,word)) {
				cout << word << " YES" << '\n';
				return;
			}
		}
	}

	cout << word << " NO" << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> tc;
	for(int i=1; i<=tc; ++i) {
		for(int r=0; r<5; ++r) {
			for(int c=0; c<5; ++c) {
				cin >> bd[r][c];
			}
		}

		int N; cin >> N;
		for(int tt=0; tt<N; ++tt) {
			cin >> word;
			sol();
		}
	}

	return 0;
}