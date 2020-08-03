#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int countTwos(int n) {

	int c = 0;

	while (!(n&1)) {
		c++;
		n >>= 1;
	}

	return c;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int acc_two_count[n+1];
		acc_two_count[0] = 0;

		for (int i = 0; i < n; i++)
			acc_two_count[i+1] = acc_two_count[i] + countTwos(a[i]);

		for (int i = 0; i < n+1; i++)
			cout << acc_two_count[i] << " ";
		cout << endl;

		map<int, int> mp;
		for (int i = 0; i <= n; i++)
			mp[acc_two_count[i]]++;

		int c = 0, diff;
		for (auto x: mp) {

			c += (x.second * (x.second-1)) / 2;

			auto up_it = mp.upper_bound(x.first - 2);
			for (auto it = mp.begin(); it != up_it; it++)
				c += x.second * (it->second);
		}

		cout << c << endl;
	}

	return 0;
}