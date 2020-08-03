#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 100001
#define COLORS 20

int n;
int dp[N][COLORS];
vector<vector<int>> g;

void dfs(int cur, int par) {

	// cout << "cur " << cur << " par " << par << endl;

	bool is_leaf = true;

	for (int neighbour: g[cur]) {
		if (neighbour == par)
			continue;

		is_leaf = false;
		dfs(neighbour, cur);
	}

	if (is_leaf) {
		for (int i = 1; i < COLORS; i++)
			dp[cur][i] = i;

		// cout << "resolved " << cur << endl;
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 1; j < COLORS; j++) {
		// 		cout << "(" << i << "," << j << ")" << dp[i][j] << " ";
		// 	}

		// 	cout << endl;
		// }

		return;
	}

	for (int col = 1; col < COLORS; col++) {
		dp[cur][col] = col;

		for (int neighbour: g[cur]) {
			if (neighbour == par)
				continue;

			int min_col_neighbour = INT_MAX;

			for (int ncol = 1; ncol < COLORS; ncol++) {
				if (ncol == col)
					continue;

				min_col_neighbour = min(min_col_neighbour, dp[neighbour][ncol]);
			}

			dp[cur][col] += min_col_neighbour;
		}
	}

	// cout << "resolved " << cur << endl;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 1; j < COLORS; j++) {
	// 		cout << "(" << i << "," << j << ")" << dp[i][j] << " ";
	// 	}

	// 	cout << endl;
	// }
}

void solve() {
	string ip;
	g.clear();
	g.resize(n);

	getline(cin, ip);

	for (int i = 0; i < n; i++) {
		getline(cin, ip);
		stringstream ss(ip);
		string s;

		ss >> s;
		while (ss >> s) {
			int v = stoi(s);
			g[i].push_back(v);
			g[v].push_back(i);
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << i << ": ";
	// 	for (auto x: g[i])
	// 		cout << x << ", ";
	// 	cout << endl;
	// }
	// cout << endl;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < COLORS; j++)
			dp[i][j] = INT_MAX;

	dfs(0, -1);

	int min_col_sum = INT_MAX;
	for (int i = 0; i < COLORS; i++)
		min_col_sum = min(min_col_sum, dp[0][i]);

	cout << min_col_sum << endl;


	// for (int i = 0; i < n; i++) {
	// 	for (int j = 1; j < COLORS; j++) {
	// 		cout << "(" << i << "," << j << ")" << dp[i][j] << " ";
	// 	}

	// 	cout << endl;
	// }
}

int main() {

	IOS

	while (cin >> n && n > 0) {
		solve();
	}

	return 0;
}