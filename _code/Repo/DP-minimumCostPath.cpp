#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 51
#define ALL_DIR 4

int dx[ALL_DIR] = {0, 1, 0, -1};
int dy[ALL_DIR] = {1, 0, -1, 0};

struct Cell {
	int x, y, dist;

	Cell(int xx, int yy, int dd) {
		x = xx;
		y = yy;
		dist = dd;
	};

	void printCell() {
		cout << x << " " << y << " " << dist << endl;
	}
};

struct sortByDistMin {

	bool operator()(Cell a, Cell b) {
		return a.dist > b.dist;
	}
};

bool valid(int x, int y, int n) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

int minCostPath(int a[][N], int n) {

	int visited[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = INT_MAX;

	priority_queue<Cell, vector<Cell>, sortByDistMin> pq;
	pq.push(Cell(0, 0, a[0][0]));
	visited[0][0] = a[0][0];

	while (!pq.empty()) {

		Cell popped = pq.top();
		pq.pop();

		// popped.printCell();

		for (int i = 0; i < ALL_DIR; i++) {
			int new_x = popped.x+dx[i];
			int new_y = popped.y+dy[i];
			int new_dist = popped.dist + a[new_x][new_y];

			if (valid(new_x, new_y, n) 
				&& 
				(visited[new_x][new_y] == INT_MAX || new_dist < visited[new_x][new_y])
			) {
				pq.push(Cell(new_x, new_y, new_dist));
				visited[new_x][new_y] = new_dist;
			}
		}
	}

	return visited[n-1][n-1];
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

		cout << minCostPath(a, n) << endl;
	}

	return 0;
}