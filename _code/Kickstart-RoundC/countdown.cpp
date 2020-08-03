#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void solve() {

	int n, k;
	cin >> n >> k;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int i = 0, req = k, c = 0;

	while (i < n) {

		// deb(a[i]);
		// deb(req);

		if (a[i] == req) {
			req--;

			if (req == 0) {
				c++;
				req = k;
			}

		} else {

			if (a[i] == k)
				req = k-1;
			else
				req = k;
		}

		i++;
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