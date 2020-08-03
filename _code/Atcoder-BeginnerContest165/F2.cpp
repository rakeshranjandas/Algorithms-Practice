#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef vector<vector<int>> vvi;

void DFS(vvi &graph, int cur, ll weight[], set<ll> &acc, int res[], int par = 0) {

	int val = weight[cur];
	bool last_erased = false, inserted = false;
	ll last_erased_val;

	if (acc.find(val) == acc.end()) {
		// Not present
		auto it = acc.upper_bound(val);
		if (it != acc.end()) {
			last_erased_val = *it;
			last_erased = true;
			acc.erase(it);
		}

		inserted = true;
		acc.insert(val);
	}

	res[cur] = acc.size();

	for (int x: graph[cur])
		if (x != par)
			DFS(graph, x, weight, acc, res, cur);

	if (inserted)
		acc.erase(acc.find(val));	

	if (last_erased) {
		acc.insert(last_erased_val);
	}
	
}

void SOLVE(vvi &graph, ll weight[], int n) {

	int res[n+1];

	set<ll> acc;

	DFS(graph, 1, weight, acc, res);

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