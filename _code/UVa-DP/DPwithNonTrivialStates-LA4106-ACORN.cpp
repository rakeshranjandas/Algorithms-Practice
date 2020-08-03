#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 2001

int t, h, f;
int acorn[N][N], dp[N];
int res;

void findMaxCorns() {
	for (int tree = 0; tree < t; tree++)
		dp[h] = max(dp[h], acorn[tree][h]);

	for (int level = h-1; level >= 0; level--) {
		for (int tree = 0; tree < t; tree++) {
			acorn[tree][level] += max(
				acorn[tree][level+1],
				level+f <= h ? dp[level+f] : 0
			);

			dp[level] = max(dp[level], acorn[tree][level]);
		}
	}

	cout << dp[0] << endl;
}

void setCorns() {
	for (int i = 0; i < t; i++) {
		int c, x;
		cin >> c;

		for (int j = 0; j < c; j++) {
			cin >> x;
			acorn[i][x]++;
		}
	}

	// for (int level = h; level >= 0; level--) {
	// 	for (int tree = 0; tree < t; tree++) {
	// 		cout << acorn[tree][level] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;
}

void solve() {
	cin >> t >> h >> f;

	memset(acorn, 0, sizeof(acorn));
	memset(dp, 0, sizeof(dp));

	setCorns();
	findMaxCorns();
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}