#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool withinRange(int cur_x, int cur_y, int max_x, int max_y) {

	return cur_x >=0 && cur_x < max_x && cur_y >= 0 && cur_y < max_y;
}

void recursiveBFS(vector<vector<int>> &pixels,
	queue<pair<int, int>> &q, vector<vector<bool>> &discovered,
	int from_color, int to_color,
	int rows, int cols) {

	if (q.empty())
		return;

	pair<int, int> front = q.front();
	q.pop();
	int front_x = front.first, front_y = front.second;

	// cout << "front_x " << front_x << " front_y " << front_y << endl;

	pixels[front_x][front_y] = to_color;

	if (withinRange(front_x-1, front_y, rows, cols) && !discovered[front_x-1][front_y] && pixels[front_x-1][front_y] == from_color) {
		q.push({front_x-1, front_y});
		discovered[front_x-1][front_y] = true;
	}

	if (withinRange(front_x+1, front_y, rows, cols) && !discovered[front_x+1][front_y] && pixels[front_x+1][front_y] == from_color) {
		q.push({front_x+1, front_y});
		discovered[front_x+1][front_y] = true;
	}

	if (withinRange(front_x, front_y-1, rows, cols) && !discovered[front_x][front_y-1] && pixels[front_x][front_y-1] == from_color) {
		q.push({front_x, front_y-1});
		discovered[front_x][front_y-1] = true;
	}

	if (withinRange(front_x, front_y+1, rows, cols) && !discovered[front_x][front_y+1] && pixels[front_x][front_y+1] == from_color) {
		q.push({front_x, front_y+1});
		discovered[front_x][front_y+1] = true;
	}

	recursiveBFS(pixels, q, discovered, from_color, to_color, rows, cols);
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

		vector<vector<int>> pixels;
		int ip;

		for (int i = 0; i < n; i++) {
			vector<int> v;
			for (int j = 0; j < m; j++) {
				cin >> ip;
				v.push_back(ip);
			}
			pixels.push_back(v);
		}

		int x, y, k;
		cin >> x >> y >> k;

		queue<pair<int, int>> q;
		q.push({x, y});

		vector<vector<bool>> discovered(n, vector<bool> (m, false));
		discovered[x][y] = true;

		// for (auto x: discovered) {
		// 	for (auto y: x) {
		// 		cout << y;
		// 	}
		// 	cout << endl;
		// }

		recursiveBFS(pixels, q, discovered, pixels[x][y], k, n, m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cout << pixels[i][j] << " ";

		cout << endl;
	}

	return 0;
}