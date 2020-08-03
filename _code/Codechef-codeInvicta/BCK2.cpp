#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << " " << a[i];
	cout << endl;
}

void dfs(vector<vector<pair<int, int>>> &graph, int n, int cur,
	int node_count[], int visited[], long long int *ans) {

	node_count[cur] = 1;
	visited[cur] = true;

	for (auto edge: graph[cur]) {

		if (visited[edge.first])
			continue;

		dfs(graph, n, edge.first, node_count, visited, ans);

		node_count[cur] += node_count[edge.first];

		*ans += 2*((long long int) min(node_count[edge.first], n-node_count[edge.first]) * edge.second);
	}

}

long long int solve(vector<vector<pair<int, int>>> &graph, int n) {

	int node_count[n+1] = {0};
	int visited[n+1] = {0};
	long long int ans = 0;

	dfs(graph, n, 1, node_count, visited, &ans);

	return ans;
}

int main() {

	FILE_WR
	IOS


	int n;
	cin >> n;

	vector<pair<int, int>> v;
	vector<vector<pair<int, int>>> graph(n+1, v);
	
	int a, b, c;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	cout << solve(graph, n) << endl;

	return 0;
}