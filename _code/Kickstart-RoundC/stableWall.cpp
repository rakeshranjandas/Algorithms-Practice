#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define R 31
#define C 31

bool dfs(map<char, set<char>> &graph, map<char, bool> &visited,
	char cur, string &chain, set<char> &current_stack) {

	// deb(cur);
	// deb(chain);

	visited[cur] = true;

	current_stack.insert(cur);

	bool can = true;

	for (auto x: graph[cur]) {
		
		if (current_stack.find(x) != current_stack.end())
			return false;

		if (visited[x])
			continue;

		can = dfs(graph, visited, x, chain, current_stack);

		if (!can)
			return false;
	}

	current_stack.erase(cur);
	chain += cur;

	return true;
}

void solve() {

	int row, col;
	cin >> row >> col;

	char a[row][col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> a[i][j];

	map<char, set<char>> graph;

	for (int i = 0; i < row-1; i++) {
		for (int j = 0; j < col; j++) {
			if (a[i+1][j] != a[i][j]) {
				graph[a[i][j]].insert(a[i+1][j]);
			}
		}
	}

	// for (auto x: graph) {
	// 	cout << x.first << " - ";
	// 	for (auto xx: x.second) {
	// 		cout << xx << ", ";
	// 	}
	// 	cout << endl;
	// }

	map<char, bool> visited;
	string chain = "";
	set<char> current_stack;

	bool can = true;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			if (!can)
			break;

			if (!visited[a[i][j]])
				can = dfs(graph, visited, a[i][j], chain, current_stack);
		}
	}

	// for (auto x: graph) {
	// 	if (!can)
	// 		break;

	// 	if (!visited[x.first])
	// 		can = dfs(graph, visited, x.first, chain, current_stack);
	// }
	
	cout << (!can ? "-1" : chain);
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		cout << "Case #" << t_i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}