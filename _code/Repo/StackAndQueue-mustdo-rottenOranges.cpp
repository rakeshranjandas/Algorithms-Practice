#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct orange {
	int x, y, time;
	orange(int xx, int yy, int t) {
		x = xx;
		y = yy;
		time = t;
	}
};

bool valid(int x, int y, int n, int m) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void printQueue(queue<orange> q) {

	while (!q.empty()) {
		cout << "(" << q.front().x << "," << q.front().y << ")" << q.front().time << " , ";
		q.pop();
	}
	cout << endl;
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

		int a[n][m], max_time = 0;
		queue<orange> q;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 2)
					q.push(orange(i, j, 0));
			}

		int i, j, time;
		while (!q.empty()) {

			// printQueue(q);
			orange front_o = q.front();
			i = front_o.x;
			j = front_o.y;
			time = front_o.time;

			max_time = max(max_time, time);
			q.pop();

			if (valid(i-1, j, n, m) && a[i-1][j] == 1) {
				a[i-1][j] = 2;
				q.push(orange(i-1, j, time+1));
			}

			if (valid(i+1, j, n, m) && a[i+1][j] == 1) {
				a[i+1][j] = 2;
				q.push(orange(i+1, j, time+1));
			}

			if (valid(i, j-1, n, m) && a[i][j-1] == 1) {
				a[i][j-1] = 2;
				q.push(orange(i, j-1, time+1));
			}

			if (valid(i, j+1, n, m) && a[i][j+1] == 1) {
				a[i][j+1] = 2;
				q.push(orange(i, j+1, time+1));
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1) {
					max_time = -1;
					break;
				}

			if (max_time == -1)
				break;
		}

		cout << max_time << endl;
		
	}

	return 0;
}