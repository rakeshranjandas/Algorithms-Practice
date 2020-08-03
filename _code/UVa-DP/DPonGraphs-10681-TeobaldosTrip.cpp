#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int c, l, s, e, d;

void solve() {

	bool g[c+1][c+1] = {0};
	int a, b;

	for (int i = 0; i < l; i++) {
		cin >> a >> b;
		g[a][b] = true;
		g[b][a] = true;
	}

	// for (int i = 1; i <= c; i++) {
	// 	for (int j = 1; j <= c; j++)
	// 		cout << g[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << endl;

	cin >> s >> e >> d;

	bool dp[c+1][d+1];
	memset(dp, 0, sizeof(dp));

	dp[e][d] = true;

	for (int day = d; day > 0; day--) {

		for (int city = 1; city <= c; city++) {
			if (dp[city][day]) {

				for (int ci = 1; ci <= c; ci++)	{
					if (ci == city)
						continue;

					if (!g[city][ci])
						continue;

					dp[ci][day-1] = true;
				}
			}
		}
	}

	// for (int i = 0; i <= c; i++) {
	// 	for (int j = 0; j <= d; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }

	if (dp[s][0])
		cout << "Yes, Teobaldo can travel." << endl;
	else
		cout << "No, Teobaldo can not travel." << endl;
}

int main() {

	IOS

	while ((cin >> c >> l) && (c > 0 || l > 0)) {
		solve();
	}

	return 0;
}