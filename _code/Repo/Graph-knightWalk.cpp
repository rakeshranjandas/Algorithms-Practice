#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define N 25
#define TOTAL_MOVES 8

int dx[TOTAL_MOVES] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[TOTAL_MOVES] = {-1, 1, -2, 2, -2, 2, -1, 1};

class Move {
	public:

	int x, y, count;

	Move(int xx, int yy, int cc) {
		x = xx;
		y = yy;
		count = cc;
	}
};

bool inRange(int x, int y, int n, int m) {
	// cout << m << n << "insideInRange" << endl;
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool unVisited(int cell_val) {
	return cell_val == 0;
}

bool sameVal(int x, int y, int xx, int yy) {
	return x == xx && y == yy;
}

int minMoves(int a[][N], int n, int m, int start_x, int start_y, int dest_x, int dest_y) {

	// cout << start_x << " " << start_y << dest_x << dest_y << endl;

	if (sameVal(start_x, start_y, dest_x, dest_y))
		return 0;

	queue<Move> q;

	q.push(Move(start_x, start_y, 0));
	a[start_x][start_y] = -1;

	int num_moves = -1;
	bool found = false;

	while (!q.empty()) {

		if (found)
			break;

		auto popped = q.front();
		q.pop();


		// cout << popped.x << "," << popped.y << endl;

		for (int i = 0; i < TOTAL_MOVES; i++) {
			int x = popped.x + dx[i];
			int y = popped.y + dy[i];
			int count = popped.count+1;

			if (inRange(x, y, n, m) && unVisited(a[x][y])) {

				// cout << " " << x << " " << y << " count=" << count << endl;

				if (sameVal(x, y, dest_x, dest_y)) {
					num_moves = count;
					found = true;
					break;
				}

				q.push(Move(x, y, count));
				a[x][y] = -1;

			}
		}
	}

	return num_moves;
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
		int n, m;
		cin >> n >> m;

		int a[N][N] = {0};

		int start_x, start_y, dest_x, dest_y;
		cin >> start_x >> start_y >> dest_x >> dest_y;

		start_x--, start_y--, dest_x--, dest_y--;

		cout << minMoves(a, n, m, start_x, start_y, dest_x, dest_y) << endl;
	}

	return 0;
}