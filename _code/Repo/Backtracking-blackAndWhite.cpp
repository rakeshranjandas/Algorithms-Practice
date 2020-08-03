#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define KILL_STEPS 9

int dx[KILL_STEPS] = {0, -2, -2, 2, 2, 1, -1, 1, -1};
int dy[KILL_STEPS] = {0, 1, -1, 1, -1, 2, 2, -2, -2};

bool kills(int b_i, int b_j, int w_i, int w_j) {

	for (int i = 0; i < KILL_STEPS; i++)
		if (b_i + dx[i] == w_i && b_j + dy[i] == w_j)
			return true;

	return false;
}

bool isInFull(int b_i, int b_j, int n, int m) {
	return 2 <= b_i && b_i <= n-3 && 2 <= b_j && b_j <= m-3;
}

bool valid(int x, int y, int n, int m) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int killPos(int b_i, int b_j, int n, int m) {

	int c = 0;

	for (int i = 0; i < KILL_STEPS; i++)
		if (valid(b_i + dx[i], b_j + dy[i], n, m))
			c += 1;

	return c;
}

int possibleWays(int n, int m) {

	int num_ways = 0;

	for (int b_i = 0; b_i < n; b_i++) {
		for (int b_j = 0; b_j < m; b_j++) {

			// if (isInFull(b_i, b_j, n, m)) {
			// 	num_ways += n*m - KILL_STEPS;
			// 	continue;
			// }

			// for (int w_i = 0; w_i < n; w_i++) {
			// 	for (int w_j = 0; w_j < m; w_j++) {

			// 		if (!kills(b_i, b_j, w_i, w_j))
			// 			num_ways++;
			// 	}
			// }

			num_ways += n*m - killPos(b_i, b_j, n, m);
		}
	}

	return num_ways;
}

int fmax(int n) {
	return max(0, n);
}

int possibleWays2(int n, int m) {

	int total_sq = n*m, sec_0, sec_1, sec_2, sec_3, sec_4, sec_5;

	int fullSquares = fmax(n-4) * fmax(m-4);

	sec_0 = fullSquares * (total_sq - 9);

	sec_1 = fmax(n-4) * 2 * (total_sq - 6);
	sec_1 += fmax(m-4) * 2 * (total_sq - 6);

	sec_2 = fmax(n-4) * 2 * (total_sq - 4);
	sec_2 += fmax(m-4) * 2 * (total_sq - 4);

	sec_3 = 4 * (total_sq - 4);
	sec_4 = 8 * (total_sq - 3);
	sec_5 = 4 * (total_sq - 2);

	deb(sec_0);
	deb(sec_1);
	deb(sec_2);
	deb(sec_3);
	deb(sec_4);
	deb(sec_5);



	int total = sec_0 + sec_1 + sec_2 + sec_3 + sec_4 + sec_5;

	return total;
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

		cout << possibleWays(n, m) << endl;

		// cout << possibleWays2(n, m) << endl;
	}

	return 0;
}