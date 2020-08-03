#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

ll findVal(ll a[], int l, int r) {
	int sig = 1, k = 1;
	ll sum = 0;
	l--; r--;

	for (int i = l; i <= r; i++) {
		sum += sig * k * a[i];
		k++;
		sig *= -1;
	}

	return sum;
}

void solve() {

	int n, q;
	cin >> n >> q;

	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	char qtype;
	int l, r;
	ll sum = 0;

	while (q--) {
		cin >> qtype >> l >> r;

		if (qtype == 'Q') {
			sum += findVal(a, l, r);

		} else {
			a[(int)(l-1)] = r; 
		}

		// for (int i = 0; i < n; i++)
		// 	cout << a[i] << " ";
		// cout << endl;
	}

	cout << sum;
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