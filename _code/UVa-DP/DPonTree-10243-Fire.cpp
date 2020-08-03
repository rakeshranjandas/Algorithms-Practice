#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int n;
vector<bool> seen;

int dfs(int cur, int is_part_of_cover, vector<vector<int>> &g, vector<vector<int>> &dp) {

	if (dp[cur][is_part_of_cover] != -1) {
		return dp[cur][is_part_of_cover];
	}

	int ret = 0;
	seen[cur] = true;

	if (is_part_of_cover) {

		for (int neighbour: g[cur]) {
			if (seen[neighbour])
				continue;

			ret += min(dfs(neighbour, 0, g, dp), dfs(neighbour, 1, g, dp));
		}

		ret++;

	} else {

		for (int neighbour: g[cur]) {
			if (seen[neighbour])
				continue;

			ret += dfs(neighbour, 1, g, dp);
		}
	}

	seen[cur] = false;
	dp[cur][is_part_of_cover] = ret;

	return dp[cur][is_part_of_cover];
}

void solve() {
	vector<vector<int>> g(n+1);

	int ne, v;

	for (int i = 1; i <= n; i++) {
		cin >> ne;
		for (int j = 0; j < ne; j++) {
			cin >> v;
			g[i].push_back(v);
		}
	}

	if (n == 1) {
		cout << 1 << endl;
		return;
	}

	vector<vector<int>> dp(n+1, vector<int> (2, -1));
	seen.resize(n+1, false);

	cout << min(dfs(1, 0, g, dp), dfs(1, 1, g, dp)) << endl;
}

int main() {

	IOS

	while (cin >> n && n > 0) {
		solve();
	}

	return 0;
}