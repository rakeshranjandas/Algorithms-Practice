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
		int n;
		cin >> n;

		int a[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		int l, r, mid, count_zeroes, total_count_zeroes = 0;

		for (int i = 0; i < n; i++) {

			sort(a[i], a[i]+n);

			if (a[i][n-1] == 0) {
				count_zeroes = n;
				// cout << "all zeroes ";

			} else if (a[i][0] == 1) {
				count_zeroes = 0;
				// cout << "all ones ";

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

				count_zeroes = l;
				// cout << "by this " << l << " ";
			}

			total_count_zeroes += count_zeroes;				
		}

		cout << total_count_zeroes << endl;
	}

	return 0;
}