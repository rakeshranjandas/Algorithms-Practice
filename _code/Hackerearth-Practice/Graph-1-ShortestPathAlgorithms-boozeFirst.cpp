#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define vvpi vector<vector<pair<int, int>>>

void dijkstra(vvpi graph, int n, int dist[]) {

	bool visited[n+1] = {0};
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, 0});
	dist[0] = 0;

	while (!pq.empty()) {
		auto popped = pq.top();
		pq.pop();

		int cur_dist = popped.first;
		int cur_pt = popped.second;

		if (visited[cur_pt])
			continue;

		visited[cur_pt] = true;

		for (auto edge: graph[cur_pt]) {
			int new_pt = edge.first;
			int edge_dist = edge.second;

			if (visited[new_pt])
				continue;

			int new_dist = dist[cur_pt]	 + edge_dist;

			if (new_dist <= dist[new_pt]) {
				pq.push({new_dist, new_pt});
				dist[new_pt] = new_dist;
			}
		}
	}
}

int main() {

	FILE_WR
	IOS

	int n, m;
	cin >> n >> m;

	vvpi graph;
	graph.resize(n+1);

	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	int b, b_i;
	cin >> b;

	for (int i = 0; i < b; i++) {
		cin >> b_i;
		graph[0].push_back({b_i, 0});
		graph[b_i].push_back({0, 0});
	}

	int dist[n+1];
	fill(dist, dist+n+1, INT_MAX);

	dijkstra(graph, n, dist);

	for (int i = 1; i <= n; i++)
		cout << dist[i] << endl;

	return 0;
}