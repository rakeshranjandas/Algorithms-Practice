#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define MAXN 301
#define MAXS 90001

int eModSq(int x, int y) {
	return x*x + y*y;
}

void solve() {
	int m, s;
	cin >> m >> s;

	int coin[m][2];
	for (int i = 0; i < m; i++)
		cin >> coin[i][0] >> coin[i][1];

	vector<vector<int>> dp(MAXN, vector<int>(MAXN, INT_MAX));
	vector<int> min_coins(MAXS, INT_MAX);

	for (int i = 0; i < m; i++) {
		dp[coin[i][0]][coin[i][1]] = 1, dp[coin[i][0]][coin[i][1]];
		min_coins[eModSq(coin[i][0], coin[i][1])] = 1;

		for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < MAXN; k++) {
				if (dp[j][k] == INT_MAX)
					continue;

				int e_mod_sq = eModSq(j + coin[i][0], k + coin[i][1]);

				if (e_mod_sq > MAXS)
					break;

				dp[j + coin[i][0]][k + coin[i][1]] = min(1 + dp[j][k], dp[j + coin[i][0]][k + coin[i][1]]);
				min_coins[e_mod_sq] = min(min_coins[e_mod_sq], dp[j + coin[i][0]][k + coin[i][1]]);
			}
		}
	}

	cout << (min_coins[s*s] == INT_MAX ? "not possible" : to_string(min_coins[s*s])) << endl;
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