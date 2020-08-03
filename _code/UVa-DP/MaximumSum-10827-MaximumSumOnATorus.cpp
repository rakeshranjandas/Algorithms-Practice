#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int kadane(vector<int> &a, int start, int end) {
	int acc = 0, max_sum = INT_MIN;

	for (int i = start; i < end; i++) {
		acc += a[i];

		if (acc < 0) {
			acc = a[i];
		}
		
		max_sum = max(max_sum, acc);
	}

	return max_sum;
}

int kadaneWithLimit(vector<int> &a, int n, int limit) {

	int max_sum = INT_MIN;

	for (int i = 0; i+limit <= n; i++)
		max_sum = max(max_sum, kadane(a, i, i+limit));

	return max_sum;

	// int max_sum = INT_MIN, acc = 0, st = 0;

	// // for (int x: a)
	// // 	cout << x << " ";
	// // cout << endl;

	// for (int i = 0; i < n; i++) {

	// 	if (st <= i-limit) {
	// 		acc -= a[st];
	// 		st++;

	// 		for (int j = st; j < i; j++) {
	// 			if (acc - a[j] > acc) {
	// 				acc -= a[j];
	// 				st = j+1;

	// 			} else {
	// 				break;
	// 			}
	// 		}
	// 	}

	// 	acc += a[i];

	// 	if (acc < 0) {
	// 		acc = a[i];
	// 		st = i;
	// 	}
		
	// 	// deb(i); deb(acc);

	// 	max_sum = max(max_sum, acc);
	// }

	// // deb(max_sum);
	// // cout << "-----------------------\n\n";

	// return max_sum;
}

int maxSumOnTorus(vector<vector<int>> &v) {

	int n = v.size();
	int n2 = 2*n-1;

	// Expand
	vector<vector<int>> a(n2, vector<int>(n2));

	for (int i = 0; i < n2; i++)
		for (int j = 0; j < n2; j++)
			a[i][j] = v[i%n][j%n];

	int max_sum = INT_MIN;

	// For all row as starting
	for (int row = 0; row < n2; row++) {

		vector<int> acc(n2, 0);

		for (int end_row = row; end_row < min(n2, row+n); end_row++) {		
			// Compress Column
			for (int col = 0; col < n2; col++)
				acc[col] += a[end_row][col];

			// cout << "row " << row << " end_row " << end_row << endl;

			// Kadane
			max_sum = max(max_sum, kadaneWithLimit(acc, n2, n));
		}
	}

	return max_sum;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> v(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> v[i][j];

		cout << maxSumOnTorus(v) << endl;
	}

	return 0;
}