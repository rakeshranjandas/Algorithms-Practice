#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

int main() {

	FILE_WR;
	IOS;

 	int n, m, k;
 	cin >> n >> m >> k;

 	bool taken[n+1] = {0};
 	map<int, pair<int, int>> mp;

 	int l, r, c;

 	for (int i = 0; i < m; i++) {
 		cin >> l >> r >> c;
 		mp[c] = {l, r};
 	}

 	long long int cost = 0, cost_ind = 0;

	for (auto x: mp) {

		if (k <= 0)
			break;

		cost += x.first;

		for (int j = x.second.first; j <= x.second.second; j++) {

			deb(j);

			if (k <= 0)
				break;

			if (!taken[j]) {
				taken[j] = true;
				k--;
			}
		}
	}

	cout << cost << endl;

	return 0;
}