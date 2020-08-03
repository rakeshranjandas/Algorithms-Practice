#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;

	int s1[n+1], ip;
	s1[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> ip;
		s1[ip] = i;
	}

	bool flag = false;

	while (!cin.eof()) {

		int s2[n+1];
		s2[0] = 0;
		for (int i = 1; i <= n; i++) {

			if (cin.peek() == -1) {
				flag = true;
				break;
			}


			cin >> ip;
			s2[ip] = i;
		}

		if (flag)
			break;

		int dp[n+1][n+1];
		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (s1[j] == s2[i])
					dp[i][j] = 1 + dp[i-1][j-1];

				dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
			}
		}

		// cout << "  ";
		// for (int i = 0; i <= n; i++)
		// 	cout << s1[i] << " ";
		// cout << endl;

		// for (int i = 0; i <= n; i++) {
		// 	cout << (s2[i]) << " ";

		// 	for (int j = 0; j <= n; j++) {
		// 		cout << dp[i][j] << " ";
		// 	}

		// 	cout << endl;
		// }

		// deb(dp[1][2]);
		// deb(s1[2]);
		// deb(s2[1]);

		cout << dp[n][n] << endl;
	}

	return 0;
}