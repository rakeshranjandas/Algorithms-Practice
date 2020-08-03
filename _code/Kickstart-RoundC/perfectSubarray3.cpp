#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

vector<int> sq_v;

void init() {
	int i = 0;
	while (true) {
		int sq = i * i;

		if (sq > 10000001)
			break;

		sq_v.push_back(sq);

		i++;
	}
}

void solve() {

	init();

	int n;
	cin >> n;

	int a[n];

	int acc[n+1];
	acc[0] = 0;

	unordered_map<int, int> acc_mp;
	acc_mp[0]++;

	int c = 0, sum_neg = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		acc[i+1] = acc[i] + a[i];

		// deb(sum_neg);
		// deb(acc[i+1]);

		for (int k = 0; (acc[i+1] - k*k) >= sum_neg; k++) {
			int to_find = (acc[i+1] - k*k);

			// deb(k*k);
			// deb(to_find);

			if (acc_mp.find(to_find) != acc_mp.end()) {
				c += acc_mp[to_find];
				// cout << " c " << c << endl;
			}
		}

		acc_mp[acc[i+1]]++;

		if (a[i] < 0)
			sum_neg += a[i];
	}


	cout << c;
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		cout << "Case #" << t_i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}