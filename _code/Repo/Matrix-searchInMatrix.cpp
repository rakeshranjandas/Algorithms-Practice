#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAX = 30;

bool searchInMatrix(int a[MAX][MAX], int m, int n, int k) {

	// Not present in Matrix
	if (a[0][0] > k || a[m-1][n-1] < k)
		return false;

	// Binary Search on row, find lower bound
	int lo = 0, hi = m-1, mid;

	while (lo < hi) {
		cout << lo << " " << hi << " " << "-> ";

		mid = (lo+hi) / 2;

		if (a[mid][0] == k)
			return true;

		if (lo == hi-1) {
			if (k < a[hi][0])
				break;
			else {
				mid = hi;
				break;
			}
		}

		if (k < a[mid][0])
			hi = mid;

		else
			lo = mid;

		cout << lo << " " << hi << " " << endl;
	}

	cout << "mid" << mid << endl;

	return binary_search(a[mid], a[mid]+n, k);
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
		int m, n;
		cin >> m >> n;

		int a[MAX][MAX];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		int k;
		cin >> k;

		cout << searchInMatrix(a, m, n, k) << endl;
	}

	return 0;
}