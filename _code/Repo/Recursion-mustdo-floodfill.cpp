#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool withinRange(int cur_x, int cur_y, int max_x, int max_y) {

	return cur_x >=0 && cur_x < max_x && cur_y >= 0 && cur_y < max_y;
}

void recursiveDFS(vector<vector<int>> &pixels, int cur_x, int cur_y,
	int row_size, int col_size, int from_color, int new_color) {

	if (!withinRange(cur_x, cur_y, row_size, col_size))
		return;


	if (pixels[cur_x][cur_y] != from_color)
		return;
	
	pixels[cur_x][cur_y] = new_color;

	recursiveDFS(pixels, cur_x+1, cur_y, row_size, col_size, from_color, new_color);
	recursiveDFS(pixels, cur_x-1, cur_y, row_size, col_size, from_color, new_color);
	recursiveDFS(pixels, cur_x, cur_y+1, row_size, col_size, from_color, new_color);
	recursiveDFS(pixels, cur_x, cur_y-1, row_size, col_size, from_color, new_color);
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

		recursiveDFS(pixels, x, y, n, m, pixels[x][y], k);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cout << pixels[i][j] << " ";

		cout << endl;
	}

	return 0;
}