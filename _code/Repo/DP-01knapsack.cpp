#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 1001

int maxVal(int v[], int w[], int n, int capacity, int cur_ind, int dp[][N]) {

	// cout << "capacity " << capacity << ", " << "cur_ind " << cur_ind << endl;
	// deb(cur_ind);
	// deb(last_taken);

	// cout << endl;

	if (capacity < 0)
		return 0;

	if (cur_ind == n)
		return 0;

	if (dp[capacity][cur_ind] != -1)
		return dp[capacity][cur_ind];

	int valWith = 0;
	if (capacity-w[cur_ind] >= 0)
		valWith = v[cur_ind] + maxVal(v, w, n, capacity-w[cur_ind], cur_ind+1, dp);

	int valWithout = maxVal(v, w, n, capacity, cur_ind+1, dp);

	int val = max(valWith, valWithout);


	// cout << "capacity " << capacity << ", " << "cur_ind " << cur_ind << " val " << val << endl;

	dp[capacity][cur_ind] = val;

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
		int n, max_wt;
		cin >> n >> max_wt;

		int v[n], w[n];
		for (int i = 0; i < n; i++)
			cin >> v[i];

		for (int i = 0; i < n; i++)
			cin >> w[i];

		int dp[max_wt+1][N];
		for (int i = 0; i < max_wt+1; i++)
			for (int j = 0; j < n+1; j++)
				dp[i][j] = -1;

		cout << maxVal(v, w, n, max_wt, 0, dp) << endl;

		// for (int j = 0; j < n+1; j++) {
		// 	for (int i = 0; i < max_wt+1; i++)
		// 		cout << dp[j][i] << " ";

		// 	cout << endl;
		// }
	}

	return 0;
}