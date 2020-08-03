#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 500000

void dfs(bool graph[][N], int lamp[], int n, int v, int *c, bool visited[]) {
	if (visited[v])
		return;

	if (lamp[v] == 1)
		return;

	*c = *c + 1;
	visited[v] = true;

	for (int i = 0; i <= n; i++)
		if (graph[v][i])
			dfs(graph, lamp, n, i, c, visited);
}

int onStateVertices(bool graph[][N], int lamp[], int n, int v) {
	int count = 0;
	bool visited[n+1] = {0};
	dfs(graph, lamp, n, v, &count, visited);
	return count;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	bool graph[n+1][N] = {0};

	int a, b;
 
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;

		graph[a][b] = true;
	}

	int q_type, v;
	int lamp[n+1] = {0}; // 0 - means ON

	for (int i = 0; i < q; i++) {
		cin >> q_type >> v;
		// deb(q_type);
		// deb(v);

		if (q_type == 1) {
			lamp[v] = (lamp[v] + 1) % 2;

		} else {
			cout << onStateVertices(graph, lamp, n, v) << endl;
		}
	}

	return 0;
}