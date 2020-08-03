#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, m, d;
	cin >> n >> m >> d;

	int a[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int md = a[0][0] % d;
	bool can = true;

	for (int i = 0; i < n && can; i++) {
		for (int j = 0; j < m && can; j++) {
			if (a[i][j] % d != md) {
				can = false;
				break;
			}
		}
	}


	if (can) {
		int min_moves = INT_MAX, moves;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int target = a[i][j];
				moves = 0;

				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < m; jj++) {
						moves += abs(a[ii][jj] - target)/d;
					}
				}

				min_moves = min(moves, min_moves);

			}
		}

		cout << min_moves;

	} else {
		cout << -1;
	}


	return 0;
}