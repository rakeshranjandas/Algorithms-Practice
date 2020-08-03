#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef vector<vector<int>> vvi;

int findCeil(vector<ll> &v, ll val) {
	int l = 0, r = v.size()-1, mid;

	while (l < r) {
		mid = l + (r-l) / 2;

		if (v[mid] >= val)
			r = mid;
		else
			l = mid+1;
	}

	return r;
}

int LIS(vector<ll> &v) {
	int n = v.size();
	vector<ll> inc(n, LONG_MAX);
	int lis_len = 1;

	for (int i = 0; i < n; i++) {
		int new_pos = findCeil(inc, v[i]);
		inc[new_pos] = v[i];
		lis_len = max(lis_len, new_pos+1);
	}

	return lis_len;
}

void DFS(vvi &graph, int cur, ll weight[], vector<ll> &acc, int res[], bool visited[]) {

	visited[cur] = true;
	acc.push_back(weight[cur]);
	res[cur] = LIS(acc);

	for (int x: graph[cur]) {
		if (!visited[x])
			DFS(graph, x, weight, acc, res, visited);
	}

	acc.pop_back();
}

void SOLVE(vvi &graph, ll weight[], int n) {

	int res[n+1];

	vector<ll> acc;
	acc.push_back(weight[1]);

	bool visited[n+1] = {0};

	DFS(graph, 1, weight, acc, res, visited);

	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;
}

int main() {

	IOS

	int n;
	cin >> n;

	vvi graph(n+1);
	ll weight[n+1];

	for (int i = 1; i <= n; i++)
		cin >> weight[i];

	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	SOLVE(graph, weight, n);

	return 0;
}