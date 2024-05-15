#include <bits/stdc++.h>

using namespace std;

int tc = 1;

char bd[6][6];
int N;
string word;

const int d8r[8] = {-1,-1,-1,0,0,1,1,1}; const int d8c[8] = {-1,0,1,-1,1,-1,0,1};

bool hasWord(int r, int c, const string& word) {
	// base cases
	if(r < 0 || r >= 5 || c < 0 || c >= 5) return false;
	if(bd[r][c] != word[0]) return false;
	if((int)word.size() == 1) return true;

	int nr, nc;
	for(int d=0; d<8; ++d) {
		nr = r + d8r[d];
		nc = c + d8c[d];

		if(hasWord(nr,nc,word.substr(1)))
			return true;
	}

	return false;
}

void sol() {
	for(int i=0; i<5; ++i) {
		for(int j=0; j<5; ++j) {
			if(hasWord(i,j,word)) {
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> tc;
	for(int i=1; i<=tc; ++i) {
		for(int i=0; i<5; ++i) {
			for(int j=0; j<5; ++j) {
				cin >> bd[i][j];
			}
		}

		cin >> N;
		for(int tt=0; tt<N; ++tt) {
			cin >> word;
			cout << word << " ";
			sol();
		}
	}

	return 0;
}