#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 1001
#define NN 301

void init2dDP(int dp[][N], int n1, int n2) {
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			dp[i][j] = -1;
}

int LIS(int last_num, int now_ind, int a[], int n, int dp[][N]) {

	if (now_ind >= n)
		return 0;

	if (last_num > -1 && dp[last_num][now_ind] != -1)
		return dp[last_num][now_ind];

	int max_suffix_lcs = 0;
	for (int i = now_ind; i < n; i++) {
		if(a[i] > last_num) {
			int lcs_suffix = 1 + LIS(a[i], i+1, a, n, dp);
			// cout << i << " lcs_suffix " << lcs_suffix << endl;
			max_suffix_lcs = max(max_suffix_lcs, lcs_suffix);	
		}
	}

	int ret = max_suffix_lcs;
	dp[last_num][now_ind] = ret;

	// cout << "last_num " << last_num << " " << a[now_ind] << " now_ind (" << now_ind << ")" << endl;
	// cout << "max_suffix_lcs " << max_suffix_lcs << " ret " << ret << endl << endl;

	return ret;
}

int longestIncSubseqLength(int a[], int n) {
	int dp[NN][N];
	init2dDP(dp, NN, n);
	return LIS(-1, 0, a, n, dp);
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

		cout << longestIncSubseqLength(a, n) << endl;
	}

	return 0;
}