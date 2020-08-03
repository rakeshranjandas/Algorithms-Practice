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

		vector<int> res;

		int start_col = 0;
		while (m > 0 && n > 0) {

			res.push_back(a[start_col][start_col]);

			// Right
			for (int i = 1; i < n; i++)
				res.push_back(a[start_col][start_col + i]);

			// Down
			for (int i = 1; i < m; i++)
				res.push_back(a[start_col + i][start_col + n - 1]);

			if (m > 1)
				// Left
				for (int i = 1; i < n; i++)
					res.push_back(a[start_col + m - 1][start_col + n - 1 - i]);

			if (n > 1)
				// Up
				for (int i = 1; i < m-1; i++)
					res.push_back(a[start_col + m - 1 - i][start_col]);


			m -= 2;
			n -= 2;
			start_col++;
		}

		for (auto x: res)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}