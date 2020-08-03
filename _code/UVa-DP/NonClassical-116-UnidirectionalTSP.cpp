#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 10
#define M 100

int n, m;
int nrow, ncol;
int a[N][M], dp[N][M], par[N][M];
int drow[3] = {-1, 0, 1};

void resetDp() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dp[i][j] = INT_MAX;
}

void solve() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	resetDp();

	for (int row = 0; row < n; row++)
		dp[row][m-1] = a[row][m-1];

	for (int col = m-1; col > 0; col--) {
		for (int row = 0; row < n; row++) {
			
			ncol = col-1;

			for (int di = 0; di < 3; di++) {
				nrow = (row + drow[di] + n) % n;
				if (dp[row][col] + a[nrow][ncol] < dp[nrow][ncol]) {
					dp[nrow][ncol] = dp[row][col] + a[nrow][ncol];
					par[nrow][ncol] = row;
				}
			}
		}
	}

	int min_row, min_val = INT_MAX;
	for (int row = 0; row < n; row++) {
		if (dp[row][0] < min_val) {
			min_val = dp[row][0];
			min_row = row;
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << "-\n";

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++)
	// 		cout << par[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << "-----\n";

	// deb(min_row);

	int path[m];
	path[0] = min_row+1;

	for (int col = 0; col < m-1; col++) {
		min_row = par[min_row][col];
		path[col+1] = min_row+1;
	}

	for (int i = 0; i < m; i++)
		cout << path[i] << (i==m-1?"":" ");
	cout << endl;
	cout << min_val << endl;
}

int main() {

	IOS

	while (cin >> n >> m)
		solve();

	return 0;
}