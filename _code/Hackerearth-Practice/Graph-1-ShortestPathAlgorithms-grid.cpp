#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define M 1001
#define MOVES 4

int dx[MOVES] = {0, 0, 1, -1};
int dy[MOVES] = {-1, 1, 0, 0};

class CellDist {
	public:
	int x, y, dist;
	CellDist(int d, int xx, int yy) {
		dist = d;
		x = xx;
		y = yy;
	}
};

bool valid(int x, int y, int n, int m) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

bool occupied(char grid[][M], int n, int m, int x, int y) {
	return grid[x][y] == '*';
}

int main() {

	FILE_WR
	IOS

	int n, m, q_num;
	cin >> n >> m >> q_num;

	char grid[n+1][M];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> grid[i][j];

	int sx, sy;
	cin >> sx >> sy;

	int dist[n+1][m+1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = INT_MAX;

	// Perform BFS
	queue<CellDist> q;
	q.push(CellDist(0, sx, sy));
	dist[sx][sy] = 0;

	while (!q.empty()) {
		CellDist popped = q.front();
		q.pop();

		for (int i = 0; i < MOVES; i++) {
			int newx = popped.x + dx[i];
			int newy = popped.y + dy[i];

			if (!valid(newx, newy, n, m))
				continue;

			if (dist[newx][newy] != INT_MAX)
				continue;

			if (occupied(grid, n, m, newx, newy))
				continue;

			dist[newx][newy] = 1 + popped.dist;
			q.push(CellDist(dist[newx][newy], newx, newy));
		}
	}


	int tx, ty;

	for (int i = 0; i < q_num; i++) {
		cin >> tx >> ty;
		cout << (dist[tx][ty] == INT_MAX ? -1 : dist[tx][ty]) << endl;
	}

	return 0;
}