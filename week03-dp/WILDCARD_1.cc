#include <bits/stdc++.h>

using namespace std;

int tc = 1;

int N;
string W, S;
vector<string> v;
int cache[101][101];

bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if(ret != -1) return ret;

	while(w < W.size() && s < S.size()
			&& (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}

	if(w == W.size()) return ret = (s == S.size());
	if(W[w] == '*') {
		for(int skip=0; skip+s<=S.size(); ++skip) {
			if(matchMemoized(w+1, skip+s)) {
				return ret = 1;
			}
		}
	}

	return ret = 0;
}

bool match(const string& w, const string& s) {
	int pos = 0;
	while(pos < (int)w.size() && pos < (int)s.size()
			&& (w[pos] == '?' || w[pos] == s[pos])) {
		++pos;
	}

	if(pos == (int)w.size()) {
		return pos == (int)s.size();
	}
	if(w[pos] == '*') {
		for(int skip=0; pos+skip<=(int)s.size(); ++skip) {
			if(match(w.substr(pos+1), s.substr(pos+skip))) {
				return true;
			}
		}
	}

	return false;
}

void sol() {
	cin >> W;
	cin >> N;
	v.clear();

	for(int i=0; i<N; ++i) {
		memset(cache, -1, sizeof(cache));
		cin >> S;
		if(matchMemoized(0,0)) {
			v.push_back(S);
		}
	}

	sort(v.begin(), v.end());
	for(auto& x : v) {
		cout << x << "\n";
	}

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
