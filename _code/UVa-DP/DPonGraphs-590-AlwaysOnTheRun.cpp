#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int t_i = 0;
int n, k;

void solve() {

	vector<int> g[n+1][n+1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;

			int d;
			cin >> d;
			g[i][j].resize(d);

			for (int k = 0; k < d; k++) {
				cin >> g[i][j][k];
			}
		}
	}

	vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
	dp[n][k] = 0;

	for (int day = k-1; day >= 0; day--) {
		for (int city = 1; city <= n; city++) {

			for (int dest = 1; dest <= n; dest++) {

				// Dest same as current city
				if (city == dest)
					continue;

				// Dest is unreachble the next day
				if (dp[dest][day+1] == INT_MAX)
					continue;

				int period = g[city][dest].size();

				// If no flight
				if (g[city][dest][day%period] == 0)
				continue;

				dp[city][day] = min(dp[city][day], g[city][dest][day%period] + dp[dest][day+1]);
			}
		}
	}

	// for (int city = 1; city <= n; city++) {
	// 	for (int day = 0; day <= k; day++) {
	// 		cout << dp[city][day] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << "Scenario #" << ++t_i << endl;
	if (dp[1][0] == INT_MAX)
		cout << "No flight possible." << endl;
	else
		cout << "The best flight costs " << dp[1][0] << "." << endl;

	cout << endl;
}

int main() {

	IOS

	while (cin >> n >> k && (n > 0 || k > 0))
		solve();

	return 0;
}