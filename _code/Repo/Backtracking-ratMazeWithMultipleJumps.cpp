#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 51

bool valid(int x, int y, int n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool findPath(int a[][N], int n, int x, int y, unordered_map<int, unordered_map<int, int>> &umap) {

	if (!valid(x, y, n))
		return false;

	if (x == n-1 && y == n-1) {
		umap[x][y] = true;
		return true;
	}

	if (a[x][y] == 0)
		return false;

	for (int jump = 1; jump <= a[x][y]; jump++) {

		if (findPath(a, n, x, y+jump, umap)) {
			umap[x][y] = 1;
			return true;
		}

		if (findPath(a, n, x+jump, y, umap)) {
			umap[x][y] = 1;
			return true;
		}
	}

	return false;
}

void printPathGrid(int n, unordered_map<int, unordered_map<int, int>> umap) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << umap[i][j] << " ";
		cout << endl;
	}
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

		int a[n][N];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		unordered_map<int, unordered_map<int, int>> umap;

		bool path_exists = findPath(a, n, 0, 0, umap);

		if (path_exists)
			printPathGrid(n, umap);
		else
			cout << "-1" << endl;
	}

	return 0;
}