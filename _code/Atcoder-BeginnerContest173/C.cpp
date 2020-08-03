#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int h, w, k;
	cin >> h >> w >> k;

	char c[h][w];
	int black = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c[i][j];

			if (c[i][j] == '#')
				black++;
		}
	}


	int res = 0;
	int cx = 0;

	for (int row_mask = 0; row_mask < 1<<h; row_mask++) {
		set<pair<int, int>> us;
		int rm = row_mask, ri = 0;

		while (rm > 0) {
			if (rm & 1) {
				for (int j = 0; j < w; j++)
					if (c[ri][j] == '#')
						us.insert({ri, j});
			}

			ri++;
			rm >>= 1;
		}

		// cout << row_mask << " " << us.size() << endl;

		for (int col_mask = 0; col_mask < 1<<w; col_mask++) {
			set<pair<int, int>> ust = us;
			int cm = col_mask, ci = 0;

			while (cm > 0) {
				if (cm & 1) {
					for (int i = 0; i < h; i++)
						if (c[i][ci] == '#')
							ust.insert({i, ci});
				}

				ci++;
				cm >>= 1;
			}

			// cout << row_mask << " " << col_mask << " " << ust.size() << endl;

			if (black - ust.size() == k)
				res++;
		}
	}

	cout << res << endl;

	return 0;
}