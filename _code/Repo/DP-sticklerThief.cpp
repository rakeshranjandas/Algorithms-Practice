#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

void initDP(int dp[], int n) {
	for (int i = 0; i < n; i++)
		dp[i] = -1;
}

int maxVal(int a[], int n, int now, int dp[]) {

	if (now >= n)
		return 0;

	if (dp[now] != -1)
		return dp[now];

	int val = max(maxVal(a, n, now+2, dp), maxVal(a, n, now+3, dp));

	// for (int i = now+2; i < ; i++)
	// 	val = max(val, maxVal(a, n, i, dp));

	val += a[now];
	dp[now] = val;

	return val;
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

		int dp[n];
		initDP(dp, n);

		cout << max(maxVal(a, n, 0, dp), maxVal(a, n, 1, dp)) << endl;

		for (int i = 0; i < n; i++)
			cout << dp[i] << " ";
		cout << endl;
	}

	return 0;
}