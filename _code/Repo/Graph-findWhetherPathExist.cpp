#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define N 20

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool sameVal(pair<int, int> a, pair<int, int> b) {
	return a.first == b.first && a.second == b.second;
}

bool inRange(int x, int y, int n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool notWallAndUnvisited(int cell_val) {
	return cell_val != 0 && cell_val != -1;
}

void dfsPath(pair<int, int> now, pair<int, int> dest, int a[][N], int n, bool *exists) {

	// cout << "inside " << now.first << "," << now.second << endl;

	if (*exists)
		return;

	if (sameVal(now, dest)) {
		*exists = true;
		return;
	}

	a[now.first][now.second] = -1;

	for (int i = 0; i < 4; i++) {
		int x = now.first + dx[i];
		int y = now.second + dy[i];

		if (inRange(x, y, n) && notWallAndUnvisited(a[x][y]))
			dfsPath({x, y}, dest, a, n, exists);
	}
}

bool pathExists(int a[][N], int n) {

	pair<int, int> source, dest;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (a[i][j] == 1)
				source = {i, j};

			else if (a[i][j] == 2)
				dest = {i, j};
			
		}

	cout << source.first << "," << source.second << endl;
	cout << dest.first << "," << dest.second << endl;

	bool exists = false;

	dfsPath(source, dest, a, n, &exists);

	return exists;

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

		int a[N][N];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		cout << pathExists(a, n) << endl;
	}

	return 0;
}