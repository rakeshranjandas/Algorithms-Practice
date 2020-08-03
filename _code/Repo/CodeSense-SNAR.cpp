#include<iostream>
#include<cmath>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

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
		int r, c;
		cin >> r >> c;

		int val;
		int snake_i, snake_j, food_i, food_j;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> val;

				if (val == 9) {
					snake_i = i;
					snake_j = j;

				} else if (val == 1) {
					food_i = i;
					food_j = j;
				}
			}
		}

		// deb(food_i);
		// deb(food_j);
		// deb(snake_i);
		// deb(snake_j);

		int abs_diff_x = abs(food_i - snake_i);
		int abs_diff_y = abs(food_j - snake_j);

		int minm = min(abs_diff_x, abs_diff_y);
		int maxm = max(abs_diff_x, abs_diff_y);

		int rest = maxm - minm;

		// deb(minm);
		// deb(rest);

		double diag_time = (double)((int)(minm * 1.414 * 1000)) / 1000;
		double total_time = diag_time + rest;

		cout << total_time << endl;

	}

	return 0;
}