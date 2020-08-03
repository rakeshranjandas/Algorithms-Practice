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
		int m, n, q;
		cin >> m >> n >> q;

		string s[m];
		cin.ignore();

		for (int i = 0; i < m; i++) {
			getline(cin, s[i]);
			// cout << s[i] << endl;
		}

		cout << m << " " << n << " " << q << endl;

		int x, y, d, edge;
		bool flag;

		while (q--) {
			cin >> x >> y;
			edge = 1;
			flag = true;

			for (int side = 3; side <= min(m, n) && flag; side +=2) {
				d = side/2;

				if (x-d < 0 || x+d >= m || y-d < 0 || y+d >= n)
					break;

				for (int sx = x-d; sx <= x+d && flag; sx++) {
					for (int sy = y-d; sy <= y+d && flag; sy++) {
						if (s[sx][sy] != s[x][y]) {
							flag = false;
							break;
						}
					}
				}

				if (!flag)
					break;

				edge = side;
			}

			cout << edge << endl;	
		}
	}

	return 0;
}