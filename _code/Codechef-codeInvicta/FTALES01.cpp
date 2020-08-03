#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define graph vector<vector<pair<int, int>>>
#define uset unordered_set<int>

static int node_count = 0;

void bridges(graph &g, int cur, uset &h, int *count_h, int low[], int node[], bool vis[], int parent) {

	node[cur] = low[cur] = ++node_count;
	vis[cur] = true;

	// deb(cur);

	for (auto e: g[cur]) {

		int v = e.first;

		if (v == parent)
			continue;

		if (vis[v])
			low[cur] = node[v];

		else {
			bridges(g, v, h, count_h, low, node, vis, cur);

			low[cur] = min(low[cur], low[v]);

			if (low[v] > node[cur] && h.find(e.second) != h.end()) {
				*count_h = *count_h + 1;
			}
		}
	}
}

int calcHarmful(graph &g, int n, uset &h) {
	int count_h = 0;
	int low[n+1], node[n+1];
	bool vis[n+1] = {0};

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			bridges(g, i, h, &count_h, low, node, vis, 0);

	return count_h;
}

int main() {

	IOS

	int n, m;
	cin >> n >> m;

	graph g;
	g.resize(n+1);

	int u, v;

	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}

	int x, x_i;
	cin >> x;

	uset h;
	for (int i = 0; i < x; i++) {
		cin >> x_i;
		h.insert(x_i);
	}

	cout << calcHarmful(g, n, h) << endl;

	return 0;
}