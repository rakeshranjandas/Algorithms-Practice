#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

class Rock {
	public:
	int x, y, r;
	Rock(int xx, int yy, int rr) {
		x = xx, y = yy , r =rr;
	}

	Rock() {

	}
};

bool overlap(Rock r1, Rock r2) {
	return (r1.x-r2.x) * (r1.x-r2.x) + (r1.y-r2.y) * (r1.y-r2.y) <= (r1.r + r2.r) * (r1.r + r2.r); 
}

bool connectedToShore(Rock r, int shore) {
	return overlap(r, Rock(r.x, shore, 0));
}

int dijkstra(vector<vector<int>> graph, int n) {
	bool visited[n+3] = {0};

	queue<pair<int, int>> q;
	q.push({n+1, 0});
	visited[n+1] = true;

	while (!q.empty()) {
		auto popped = q.front();
		q.pop();

		if (popped.first == n+2)
			return popped.second - 1;

		for (auto x: graph[popped.first]) {
			if (visited[x])
				continue;

			q.push({x, popped.second+1});
			visited[x] = true;
		}
	}

	return -1;
}

int main() {

	FILE_WR
	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		Rock rock_v[n+1];

		int x, y, r;

		for (int i = 1; i <= n; i++) {
			cin >> x >> y >> r;
			rock_v[i] = Rock(x, y, r);
		}

		int a, b;
		cin >> a >> b;

		vector<vector<int>> graph;
		graph.resize(n+3);

		// Check overlap and create adj list
		for (int i = 1; i <= n-1; i++) {

			if (connectedToShore(rock_v[i], a)) {
				graph[n+1].push_back(i);
				graph[i].push_back(n+1);
			}

			if (connectedToShore(rock_v[i], b)) {
				graph[n+2].push_back(i);
				graph[i].push_back(n+2);
			}

			for (int j = i+1; j <= n; j++) {
				if (overlap(rock_v[i], rock_v[j])) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		if (connectedToShore(rock_v[n], a)) {
			graph[n+1].push_back(n);
			graph[n].push_back(n+1);
		}

		if (connectedToShore(rock_v[n], b)) {
			graph[n+2].push_back(n);
			graph[n].push_back(n+2);
		}

		cout << dijkstra(graph, n) << endl;

	}

	return 0;
}