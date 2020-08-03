#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int n, m, q, max_score = 0;
vector<int> a, b, c, s, seq;

int getScore() {
	int score = 0;
	for (int i = 0; i < q; i++) {
		if (seq[b[i]-1] - seq[a[i]-1] == c[i]) {
			score += s[i];
		}
	}

	return score;
}

void gen(int ind, int val) {

	if (ind == seq.size()) {

		max_score = max(max_score, getScore());

		return;
	}

	for (int i = val; i <= m; i++) {
		seq[ind] = i;
		gen(ind+1, i);
	}
}

int main() {

	IOS

	cin >> n >> m >> q;

	a.resize(q);
	b.resize(q);
	c.resize(q);
	s.resize(q);
	seq.resize(n);

	for (int i = 0; i < q; i++)
		cin >> a[i] >> b[i] >> c[i] >> s[i];

	gen(0, 1);

	cout << max_score << endl;

	return 0;
}