#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define COL 6002
#define ROW 1001
typedef long long int ll;

int dp[ROW][COL];

int main() {

	IOS

	int n;
	while (cin >> n && n > 0) {
		int w[n+1], l[n+1];

		for (int i = 1; i <= n; i++)
			cin >> w[i] >> l[i];

		memset(dp, 0, sizeof(dp));

		int max_len = 1;
		dp[n][w[n]] = 1;

		for (int box = n-1; box >= 1; box--) {

			for (int i = 1; i < COL ; i++) {
					
				dp[box][i] = max(dp[box][i], dp[box+1][i]);

				if (i <= l[box] && dp[box+1][i]) {
					dp[box][i + w[box]] = max(dp[box][i + w[box]], 1 + dp[box+1][i]);
					max_len = max(max_len, dp[box][i + w[box]]);
				}
			}

			dp[box][w[box]] = max(dp[box][w[box]], 1);
		}

		cout << max_len << endl;
	}

	return 0;
}