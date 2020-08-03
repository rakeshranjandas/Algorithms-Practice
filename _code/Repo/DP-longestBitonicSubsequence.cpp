#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 2

void init2dDP(int dp[][N], int n1, int n2) {
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			dp[i][j] = -1;
}

void print2dArr(int dp[][N], int n1, int n2) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}

int LBS(int a[], int n) {

	int dp[n][2];
	init2dDP(dp, n, 2);

	dp[n-1][0] = dp[n-1][1]= 1;
	int max_inc_dec, max_dec, max_lbs = 1;

	for (int i = n-2; i >= 0; i--) {
		max_inc_dec = 0, max_dec = 0;

		for (int j = i+1; j < n; j++) {
			if (a[j] > a[i]) {
				max_inc_dec = max(dp[j][0], max_inc_dec);

			} else if (a[j] < a[i]) {
				max_dec = max(dp[j][1], max_dec);
			}
		}

		dp[i][1] = max_dec + 1;
		dp[i][0] = max(max_inc_dec, max_dec) + 1;
		max_lbs = max(max_lbs, dp[i][0]);
	}


	print2dArr(dp, n, 2);

	return max_lbs;
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

		cout << LBS(a, n) << endl;
	}

	return 0;
}