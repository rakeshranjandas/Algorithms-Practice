#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define V 20001

int main() {

	IOS

	int t;
	cin >> t;
	int tt = 1;

	while (t--) {
		int buy;
		cin >> buy;

		int n;
		cin >> n;

		int coin[n+1];
		for (int i = 1; i <= n; i++)
			cin >> coin[i];

		vector<vector<ll>> ways(n+1, vector<ll> (V, LONG_MAX));
		ways[0][0] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < V; j++) {
				ways[i][j] = min(ways[i][j], ways[i-1][j]);

				if (ways[i-1][j] != LONG_MAX && j+coin[i] < V) {
					ways[i][j+coin[i]] = min(ways[i][j+coin[i]], ways[i-1][j] + 1);
				}

			}
		}

		// Start from amount, find nearest greater that is possible
		for (int i = buy; i < V; i++) {
			if (ways[n][i] != LONG_MAX) {
				cout << i << " " << ways[n][i] << endl;
				break;
			}
		}
	}

	return 0;
}