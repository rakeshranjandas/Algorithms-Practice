#include<iostream>
#include<climits>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

#define printArr(dp, n) for (int i = 0; i < n; i++) { cout << dp[i] << " ";}; cout << endl;

int minSteps(int a[], int n) {

	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = INT_MAX;

	dp[n-1] = 0;

	for (int i = n-2; i >= 0; i--) {
		// printArr(dp, n);

		if (i+a[i] >= n-1)
			dp[i] = 1;

		else {

			int minm = INT_MAX;
			for (int j = 1; j <= a[i]; j++)
				minm = min(minm, dp[i+j]);

			// deb(minm);

			if (minm != INT_MAX)
				dp[i] = minm + 1;
		}
	}

	return dp[0] == INT_MAX ? -1 : dp[0];
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

		cout << minSteps(a, n) << endl;
	}

	return 0;
}