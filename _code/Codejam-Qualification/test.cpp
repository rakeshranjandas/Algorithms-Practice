#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define uset unordered_set<int>

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {

		int n;
		cin >> n;

		int a[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)	
			cin >> a[i][j];

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

		cout << "Case #" << t_i << ": " << trace << " " << row_dup_count << " " << col_dup_count << endl;
	}

	return 0;
}