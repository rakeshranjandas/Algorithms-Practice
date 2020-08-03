#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void solve() {
	int m, c;
	cin >> m >> c;

	bool dp[c+1][m+1];
	memset(dp, 0, sizeof(dp));

	int k, price;

	dp[0][0] = true;

	for (int i = 1; i <= c; i++) {
		cin >> k;
		for (int ki = 0; ki < k; ki++) {
			cin >> price;
			for (int l = 0; l <= m; l++) {
				if (!dp[i-1][l])
					continue;

				if (l + price > m)
					continue;

				dp[i][l+price] = true;
			}
		}
	}

	int res = -1;
	for (int i = m; i >= 0; i--) {
		if (dp[c][i]) {
			res = i;
			break;
		}
	}

	// for (int i = 0; i <= c; i++) {
	// 	for (int j = 0; j <= m; j++)
	// 		cout << j << "(" << dp[i][j] << ")" << " ";
	// 	cout << endl;
	// }

	if (res == -1)
		cout << "no solution" << endl;
	else
		cout << res << endl;
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