#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

class Cell {
	public:
	int x, y, dist;

	Cell(int xx, int yy, int dd) {
		x = xx, y = yy, dist = dd;
	}
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y, int h, int w) {
	return x >= 1 && x <= h && y >= 1 && y <= w;
}

int main() {

	IOS

	int h, w, k;
	cin >> h >> w >> k;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int d[h+1][w+1];
	memset(d, -1, sizeof(d));

	char graph[h+1][w+1];

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> graph[i][j];

	queue<Cell> q;
	q.push(Cell(x1, y1, 0));
	d[x1][y1] = 0;
	int res = -1;

	while (!q.empty()) {
		auto popped = q.front();
		q.pop();

		// deb(popped.x);
		// deb(popped.y);

		for (int dir = 0; dir < 4; dir++) {
			for (int jump = 1; jump <= k; jump++) {

				int newx = popped.x + jump * dx[dir];
				int newy = popped.y + jump * dy[dir];

				if (!valid(newx, newy, h, w))
					break;

				if (d[newx][newy] != -1)
					break;

				if (graph[newx][newy] == '@')
					break;

				int newdist = d[popped.x][popped.y] + 1;

				q.push(Cell(newx, newy, newdist));
				d[newx][newy] = newdist;
			}
		}
	}

	cout << d[x2][y2];

	return 0;
}