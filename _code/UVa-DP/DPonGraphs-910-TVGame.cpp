#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int n, m;
int g[26][2], dp[26][31];
bool is_special[26];

int ind(char c) {
	return c - 'A';
}

int ways() {
	dp[ind('A')][0] = 1;

	for (int move = 0; move < m; move++) {
		for (int node = 0; node < n; node++) {
			if (dp[node][move] > 0) {
				dp[g[node][0]][move+1] += dp[node][move];
				dp[g[node][1]][move+1] += dp[node][move]; 
			}
		}
	}

	int c = 0;

	for (int node = 0; node < n; node++) {
		if (is_special[node])
			c += dp[node][m];
	}

	return c;
}

void solve() {
	memset(g, 0, sizeof(g));
	memset(dp, 0, sizeof(dp));
	memset(is_special, 0, sizeof(is_special));

	char node, move0, move1, special;

	for (int i = 0; i < n; i++) {
		cin >> node >> move0 >> move1 >> special;
		g[ind(node)][0] = ind(move0);
		g[ind(node)][1] = ind(move1);

		if (special == 'x')
			is_special[ind(node)] = true;
	}

	cin >> m;

	cout << ways() << endl;
}

int main() {

	IOS

	while (cin >> n) {
		solve();
	}

	return 0;
}