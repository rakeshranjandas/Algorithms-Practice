#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 3001
#define M 1001
int dp[M][N];

typedef long long int ll;

int maxStackLen(int w[], int l[], int n, int cur, int load, int dp[][N], int *lis_len, int k) {
	if (cur < 0) {
		*lis_len = max(*lis_len, k);
		return 0;
	}

	if (load > l[cur])
		return 0;

	if (dp[cur][load] != -1) {
		// deb(dp[cur][load]);
		return dp[cur][load];
	}

	int not_taken = maxStackLen(w, l, n, cur-1, load, dp, lis_len, k);
	int taken = 1 + maxStackLen(w, l, n, cur-1, load+w[cur], dp, lis_len, k+1);

	deb

	dp[cur][load] = max(taken, not_taken);

	return dp[cur][load];
}

int main() {

	IOS

	int n;
	while (cin >> n && n > 0) {
		int w[n], l[n];
		for (int i = 0; i < n; i++)
			cin >> w[i] >> l[i];

		memset(dp, -1, sizeof(dp));
		int lis_len = 0;
		maxStackLen(w, l, n, n-1, 0, dp, &lis_len, 0);
		cout << lis_len << endl;
	}

	return 0;
}