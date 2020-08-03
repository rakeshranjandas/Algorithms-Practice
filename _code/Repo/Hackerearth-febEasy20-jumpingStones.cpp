#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define M 1000000007

int noOfWays(int n, int k, int dp[]) {

	// deb(n);

	if (n == 1)
		return 1;

	if (n <= 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	int steps = 0;
	for (int i = 1; i <= k && i >= 0; i++)
		steps = (steps + noOfWays(n-i, k, dp)) % M;

	dp[n] = steps;

	return steps;
}


void initDP(int dp[], int n) {
	for (int i = 0; i < n; i++)
		dp[i] = -1;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int dp[n+1];
	initDP(dp, n+1);

	cout << noOfWays(n, k, dp) << endl;

	return 0;
}