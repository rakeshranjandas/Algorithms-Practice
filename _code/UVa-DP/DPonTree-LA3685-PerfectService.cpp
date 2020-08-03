#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 100001
#define INF 200000

int n;
vector<vector<int>> g;
int dp[N][2][2];

int countServers(int cur, int par, int is_server, int is_served) {

	if (dp[cur][is_server][is_served] != -1)
		return dp[cur][is_server][is_served];

	bool is_leaf = true;

	int c = is_server;

	if (is_server) {

		for (int child: g[cur]) {
			if (child == par)
				continue;

			is_leaf = false;

			c += min(countServers(child, cur, 0, 1), countServers(child, cur, 1, 1));

			if (c >= INF)
				break;
		}

	} else if (is_served) {

		for (int child: g[cur]) {
			if (child == par)
				continue;

			is_leaf = false;

			c += countServers(child, cur, 0, 0);

			if (c >= INF)
				break;
		}

	} else {

		int min_d = INF;

		for (int server_child: g[cur]) {
			if (server_child == par)
				continue;

			is_leaf = false;

			int d = countServers(server_child, cur, 1, 1);

			if (d == INF)
				continue;

			for (int non_server_child: g[cur]) {
				if (non_server_child == par || non_server_child == server_child)
					continue;

				d += countServers(non_server_child, cur, 0, 0);

				if (d >= INF)
					break;
			}

			min_d = min(d, min_d);
		}

		c += min_d;
	}

	if (is_leaf) {
		if (is_served == 1)
			return dp[cur][is_server][is_served] = is_server;

		return dp[cur][is_server][is_served] = INF;
	}

	return dp[cur][is_server][is_served] = min(INF, c);
}

void solve() {
	g.clear();
	g.resize(n+1);

	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	memset(dp, -1, sizeof(dp));

	cout << min(countServers(1, -1, 0, 0), countServers(1, -1, 1, 1)) << endl;
}

int main() {

	IOS

	while (cin >> n && n > -1) {
		if (n == 0)
			continue;
		solve();
	}

	return 0;
}