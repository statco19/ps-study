#include <bits/stdc++.h>

using namespace std;

int tc = 1;

string s;

string reverse(string::iterator& it) {
	char head = *it;
	++it;

	if(head == 'w' || head == 'b') {
		return string(1, head);
	}

	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string(1, head) + lowerLeft + lowerRight + upperLeft + upperRight;
}

void sol() {
	cin >> s;

	string::iterator it = s.begin();
	cout << reverse(it) << "\n";

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
