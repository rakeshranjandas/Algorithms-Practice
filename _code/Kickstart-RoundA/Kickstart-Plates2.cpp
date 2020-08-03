#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

#define K 31
#define P 1501

void init2dDP(int dp[][P], int n1, int n2) {
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			dp[i][j] = -1;
}

int maxPlatesUtil(int a[][K], int n, int k, int dp[][P], int row, int moves) {

	if (row >= n)
		return 0;

	if (dp[row][moves] != -1)
		return dp[row][moves];

	int max_val = maxPlatesUtil(a, n, k, dp, row+1, moves),
		this_stack_sum = 0;

	for (int i = 0; i < min(k, moves); i++) {
		
		this_stack_sum += a[row][i];
		max_val = max(max_val, this_stack_sum + maxPlatesUtil(a, n, k, dp, row+1, moves-(i+1)));
	}

	dp[row][moves] = max_val;

	return max_val;

}

int maxPlates(int a[][K], int n, int k, int p) {

	int dp[n][P];
	init2dDP(dp, n, p+1);

	return maxPlatesUtil(a, n, k, dp, 0, p);
}

int main() {

	FILE_WR;
	IOS;

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {

		int n, k, p;
		cin >> n >> k >> p;

		int a[n][K];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < k; j++)
				cin >> a[i][j];

		cout << "Case #" << t_i << ": " << maxPlates(a, n, k, p) << endl;
	}

	return 0;
}