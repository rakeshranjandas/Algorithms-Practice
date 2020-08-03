#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		ll a[n][m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];

		ll moves[n][m];
		ll start[n][m];
		memset(start, -1, sizeof(start));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (i == 0 && j == 0) {
					moves[i][j] = 0;
					start[i][j] = a[0][0];

				} else {
					ll lmoves = LONG_MAX, templ, tempsl;

					if (j-1 >= 0 && moves[i][j-1] != LONG_MAX) {

						if (a[i][j-1] < a[i][j]) {
							lmoves = moves[i][j-1] + a[i][j] - (a[i][j-1] + 1);
							templ = a[i][j-1] + 1;
							tempsl = start[i][j-1];

						} else {

							lmoves = moves[i][j-1] + (i+j) * (a[i][j-1] - (a[i][j] - 1));
							templ = a[i][j];

							int starta = start[i][j-1];

							tempsl = starta - (a[i][j-1] - (a[i][j] - 1));

							// if (start[i][j] < 0) {
							// 	// templ = LONG_MAX;
							// 	lmoves = LONG_MAX;
							// } 
						}
					}

					ll umoves = LONG_MAX, tempu, tempsu;

					if (i-1 >= 0 && moves[i-1][j] != LONG_MAX) {

						if (a[i-1][j] < a[i][j]) {
							umoves = moves[i-1][j] + a[i][j] - (a[i-1][j] + 1);
							tempu = a[i-1][j] + 1;
							tempsu = start[i-1][j];

						} else {

							umoves = moves[i-1][j] + (i+j) * (a[i-1][j] - (a[i][j] - 1));
							tempu = a[i][j];

							int starta = start[i-1][j];

							tempsu = starta - (a[i-1][j] - (a[i][j] - 1));

							// if (start[i][j] < 0) {
							// 	// tempu = LONG_MAX;
							// 	umoves = LONG_MAX;
							// } 
						}
					}

					if (umoves < lmoves) {
						moves[i][j] = umoves;
						a[i][j] = tempu;
						start[i][j] = tempsu;

					} else {
						moves[i][j] = lmoves;
						a[i][j] = templ;
						start[i][j] = tempsl;
					}

					cout << "i " << i << " j " << j << endl;
					deb(umoves);
					deb(lmoves);

					moves[i][j] = min(umoves, lmoves);
				}

			}

			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					cout << moves[k][l] << "(" << a[k][l] << ")" << "<" << start[k][l] << ">" << " ";
				}
				cout << endl;
			}

			cout << "----------" << endl;
		}

		cout << moves[n-1][m-1] << endl;
		cout << "==========================" << endl;
	}

	return 0;
}