#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool canChainWords(string a, string b) {
	return b[0] == a[a.size()-1];
}

void dfs(string a[], int n, int cur_ind, bool visited[],
	bool* can_chain, int level, char first) {

	// deb(level);
	// deb(a[cur_ind]);

	if (*can_chain)
		return;

	if (level == n) {
		*can_chain = a[cur_ind][a[cur_ind].size()-1] == first;
		return;
	}

	visited[cur_ind] = true;


	for (int i = 0; i < n; i++) {
		if (i == cur_ind)
			continue;

		if (visited[i])
			continue;

		if (canChainWords(a[cur_ind], a[i]))
			dfs(a, n, i, visited, can_chain, level+1, first);
	}

	visited[cur_ind] = false;
}

bool canChain(string a[], int n) {

	bool can_chain = false;
	bool visited[n] = {0};

	for (int i = 0; i < n; i++)
		if (!can_chain)
			dfs(a, n, i, visited, &can_chain, 1, a[i][0]);

	return can_chain;
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
		int n;
		cin >> n;

		string a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << canChain(a, n) << endl;
	}

	return 0;
}