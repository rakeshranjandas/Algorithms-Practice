#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

		int a[m][n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		int l, r, mid, min_count_ones = n+1, count_ones, min_count_ones_index = -1;

		for (int i = 0; i < m; i++) {
			sort(a[i], a[i]+n);

			if (a[i][n-1] == 0) {
				count_ones = 0;
				cout << "all zeroes ";

			} else if (a[i][0] == 1) {
				count_ones = n;
				cout << "all ones ";

			} else {

				l = 0;
				r = n-1;
				mid = (l+r) / 2;

				while (l < r) {
					mid = (l+r) / 2;

					if (a[i][mid] == 1)
						r = mid;

					else
						l = mid+1;
				}

				count_ones = n-l;
				cout << "by this " << l << " ";
			}

			cout << "line " << i << ": " << count_ones << endl;

			if (count_ones > 0) {
				if (count_ones < min_count_ones) {
					min_count_ones = count_ones;
					min_count_ones_index = i;
				}
			}
				
		}

		cout << min_count_ones_index << endl;
	}

	return 0;
}