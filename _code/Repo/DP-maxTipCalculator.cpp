#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 106

int maxTip(int tip_a[], int tip_b[], int n, int cur, int x, int y, int dp[][N]) {

	if (cur == n)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	int tip_by_a = 0, tip_by_b = 0;

	if (x > 0)
		tip_by_a = tip_a[cur] + maxTip(tip_a, tip_b, n, cur+1, x-1, y, dp);

	if (y > 0)
		tip_by_b = tip_b[cur] + maxTip(tip_a, tip_b, n, cur+1, x, y-1, dp);

	int max_tip = max(tip_by_a, tip_by_b);
	dp[x][y] = max_tip;

	return max_tip;
}

void init2dDP(int dp[][N], int n1, int n2) {
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
		int n, x, y;
		cin >> n >> x >> y;

		int tip_a[n], tip_b[n];
		for (int i = 0; i < n; i++)
			cin >> tip_a[i];

		for (int i = 0; i < n; i++)
			cin >> tip_b[i];

		int dp[x+1][N];
		init2dDP(dp, x+1, y+1);

		cout << maxTip(tip_a, tip_b, n, 0, x, y, dp) << endl;
	}

	return 0;
}