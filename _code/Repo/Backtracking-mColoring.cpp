#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 51

bool canColorUtil(bool g[][N], int color[], int m, int n, int node) {

	// If node is already colored
	if (color[node] != 0)
		return true;

	unordered_set<int> adj_colors, adj_uncolored_nodes;

	// Check available colors
	for (int i = 1; i <= n; i++) {
		if (g[node][i]) {
			if (color[i] != 0)
				adj_colors.insert(color[i]);
			else
				adj_uncolored_nodes.insert(i);
		}
	}

	bool can_assign_this_color = false;
	for (int col = 1; col <= m; col++) {
		if (adj_colors.find(col) == adj_colors.end()) {
			color[node] = col;

			if (adj_uncolored_nodes.size() == 0)
				return true;

			for (auto next_node: adj_uncolored_nodes) {
				can_assign_this_color = canColorUtil(g, color, m, n, next_node);

				if (!can_assign_this_color)
					break;
			}

			if (can_assign_this_color)
				return true;
		}
	}

	if (!can_assign_this_color)
		color[node] = 0;

	return can_assign_this_color;
}

bool canColor(bool g[][N], int color[], int m, int n) {

	bool possible = true;
	for (int i = 1; i <= n; i++)
		possible &= canColorUtil(g, color, m, n, i);

	return possible;
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
		int n, m, e;
		cin >> n >> m >> e;

		bool g[n+1][N] = {0};
		int a, b;

		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			g[a][b] = g[b][a] = true;
		}

		int color[n+1] = {0};

		cout << canColor(g, color, m, n) << endl;
	}

	return 0;
}