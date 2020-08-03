#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define N 51
#define uset unordered_set<int>

void printArr(int a[][N], int n) {

	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

bool isTraceOk(int a[][N], int n, int k) {
	int trace = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				trace += a[i][j];

	return trace == k;
}

bool fill(int a[][N], int n, int k, bool row_used[][N], bool col_used[][N],
	int row = 0, int col = 0) {

	// return true;

	// printArr(a, n);

	// deb(row);
	// deb(col);

	if (row == n) {
		return isTraceOk(a, n, k);
	}

	for (int i = 1; i <= n; i++) {
		if (!row_used[row][i] && !col_used[col][i]) {
			a[row][col] = i;
			row_used[row][i] = true;
			col_used[col][i] = true;

			int next_row = row, next_col = col + 1;

			if (next_col == n) {
				next_col = 0;
				next_row++;
			}

			bool isPossible = fill(a, n, k, row_used, col_used, next_row, next_col);

			if (isPossible)
				return true;

			else {
				// Revert
				a[row][col] = 0;
				row_used[row][i] = false;
				col_used[col][i] = false;
			}
		}
	}

	return false;
}

bool isCorrect(int a[][N], int n) {
	int trace = 0;
	uset row_set[n], col_set[n];
	bool row_dup[n] = {0}, col_dup[n] = {0};
	int row_dup_count = 0, col_dup_count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i == j)
				trace += a[i][j];

			if (row_set[i].find(a[i][j]) != row_set[i].end()) {
				if (!row_dup[i])
					row_dup_count++;
				row_dup[i] = true;
			}

			row_set[i].insert(a[i][j]);

			if (col_set[j].find(a[i][j]) != col_set[j].end()) {
				if (!col_dup[j])
					col_dup_count++;
				col_dup[j] = true;
			}

			col_set[j].insert(a[i][j]);
		}
	}

	return col_dup_count == 0 && row_dup_count == 0;
}

void produce(int n, int k) {

	int a[n][N] = {0};
	bool row_used[n][N] = {0}, col_used[n][N] = {0};

	bool can_fill;

	if (k < n)
		can_fill = false;

	else
		can_fill = fill(a, n, k, row_used, col_used);

	if (can_fill) {
		cout << "POSSIBLE ";
		printArr(a, n);

		cout << isCorrect(a, n) << endl;

	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main() {

	IOS

	for (int n = 2; n <= 5; n++) {
		for (int k = 1; k <= n*n; k++) {
			cout<< n << " " << k << " ";
			 produce(n, k);
		}
	}

	// int t;
	// cin >> t;

	// for (int t_i = 1; t_i <= t; t_i++) {

	// 	int n, k;
	// 	cin >> n >> k;

	// 	cout << "Case #" << t_i << ": ";
	// 	produce(n, k);
	// }

	return 0;
}