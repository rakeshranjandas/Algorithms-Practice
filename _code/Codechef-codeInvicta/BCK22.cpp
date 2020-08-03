#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define vpi vector<pair<int, int>> 

int dfs(vector<vpi> &graph, int n, int cur,
	bool visited[], ll *ans) {

	visited[cur] = true;
	int node_count = 1, subtree_count;


	for (auto edge: graph[cur]) {
		if (visited[edge.first])
			continue;

		subtree_count = dfs(graph, n, edge.first, visited, ans);
		node_count += subtree_count;

		*ans += 2 * ((ll) min(subtree_count, n-subtree_count) * edge.second);
	}

	return node_count;
}

ll solve(vector<vpi> &graph, int n) {
	ll ans = 0;
	bool visited[n+1] = {0};

	dfs(graph, n, 1, visited, &ans);

	return ans;
}

int main() {

	FILE_WR
	IOS

	int n;
	cin >> n;

	vpi v;
	vector<vpi> graph(n+1, v);
	
	int a, b, c;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	cout << solve(graph, n) << endl;

	return 0;
}