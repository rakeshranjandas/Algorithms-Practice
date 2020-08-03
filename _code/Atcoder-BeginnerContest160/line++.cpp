#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	FILE_WR
	IOS

	int n, x, y;
	cin >> n >> x >> y;

	int dist[n+1][n+1] = {0};

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			dist[i][j] = dist[j][i] = abs(i-j);
		}
	}

	map<int, int> dist_count;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			dist[i][j] = min(dist[i][j], dist[i][x] + dist[j][y] + 1);

			// deb(i); deb(j); deb(dist[i][j]); deb(dist[i][x]); deb(dist[j][y]);

			dist_count[dist[i][j]]++;
		}
	}

	for (int i = 1; i <= n-1; i++)
		cout << dist_count[i] << endl;
}