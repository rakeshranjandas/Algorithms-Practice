#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 301

long long int possibleWays(int a[], int n, int k, int now, int dp[][N]) {

	if (k == 0)
		return 1;

	if (k < 0)
		return 0;

	if (dp[k][now] > 0)
		return dp[k][now];

	long long int ways = 0;

	for (int i = now; i < n; i++)
		ways += possibleWays(a, n, k-a[i], i, dp);

	dp[k][now] = ways;

	return ways;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

		int dp[k+1][N] = {0};

		cout << possibleWays(a, n, k, 0, dp) << endl;

		// for (int i = 0; i < k+1; i++) {
		// 	for (int j = 0; j < n; j++) {
		// 		cout << "dp " << i << " " << j << " " << dp[i][j] << endl;
		// 	}
		// }

			
		// cout << endl;
	}

	return 0;
}