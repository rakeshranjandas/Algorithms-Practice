#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

#define N 51

void init2dDP(int dp[][N], int n1, int n2) {
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			dp[i][j] = -1;
}

void print2d(int a[][N], int n1, int n2) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			cout << a[i][j] << " ";
		}

		cout << endl;
	}
}

int largestSquare(int a[][N], int r, int c, int x, int y, int dp[][N], int *max_sq_size) {

	if (x >= r || y >= c)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	int right_sq = largestSquare(a, r, c, x, y+1, dp, max_sq_size);
	int bottom_sq = largestSquare(a, r, c, x+1, y, dp, max_sq_size);
	int rightbottom_sq = largestSquare(a, r, c, x+1, y+1, dp, max_sq_size);

	int sq_size = min(min(rightbottom_sq, bottom_sq), right_sq);
	int this_sq_size = a[x][y] ? sq_size+1: 0;

	*max_sq_size = max(this_sq_size, *max_sq_size);
	dp[x][y] = this_sq_size;

	// cout << "x" << x << " y" << y << " " << this_sq_size <<  endl;

	return this_sq_size; 
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
		int r, c;
		cin >> r >> c;

		int a[r][N];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> a[i][j];

		int dp[r][N];
		init2dDP(dp, r, c);

		int max_sq_size = 0;
		largestSquare(a, r, c, 0, 0, dp, &max_sq_size);

		cout << max_sq_size << endl;

		// print2d(a, r, c);
		// cout << endl;
		// print2d(dp, r, c);

	}

	return 0;
}