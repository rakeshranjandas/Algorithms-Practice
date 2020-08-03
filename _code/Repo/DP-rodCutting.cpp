#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 101

int maxProfit(int a[], int n, int rem, int dp[][N]) {

	if (n <= 0)
		return 0;

	if (dp[rem][n] != -1)
		return dp[rem][n];

	int with = 0;

	if (rem-n >= 0)
		with = a[n] + maxProfit(a, n, rem-n, dp);

	int without = maxProfit(a, n-1, rem, dp);
	int maxVal = max(with, without);

	dp[rem][n] = maxVal;

	return maxVal;
}

void initDP(int dp[][N], int n1, int n2) {
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			dp[i][j] = -1;
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
		
		int a[n+1];
		for (int i = 1; i < n+1; i++)
			cin >> a[i];

		int dp[n+1][N];
		initDP(dp, n+1, n+1);

		cout << maxProfit(a, n, n, dp) << endl;
	}

	return 0;
}