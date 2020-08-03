#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printCol(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int findMaxSum(int a[], int n) {
	int max_sum = INT_MIN, r = 0;

	for (int i = 0; i < n; i++) {
		r += a[i];

		max_sum = max(r, max_sum);

		if (r <= 0)
			r = 0;
	}

	// deb(max_sum);
	return max_sum;

}

int main() {

	IOS

	int n;
	while (cin >> n) {

		int a[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		int col_sum[n];
		int max_sum = INT_MIN;

		for (int i = 0; i < n; i++) {
			memset(col_sum, 0, sizeof(col_sum));

			for (int col = i; col < n; col++) {
				for (int row = 0; row < n; row++) {
					col_sum[row] += a[row][col];
				}

				max_sum = max(max_sum, findMaxSum(col_sum, n));
				// printCol(col_sum, n);
			}
		}

		cout << max_sum << endl;
	}

	return 0;
}