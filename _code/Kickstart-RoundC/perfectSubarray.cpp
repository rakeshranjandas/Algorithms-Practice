#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

unordered_set<int> sq_set;

void init() {
	int i = 0;
	while (true) {
		int sq = i * i;

		if (sq > 10000001)
			break;

		sq_set.insert(sq);

		i++;
	}
}

bool isPerfectSquare(int num) {
	if (num < 0)
		return false;

	return sq_set.find(num) != sq_set.end();

	// deb(num);
	// deb(sqrt(num));
	// deb((double)num)

	// int sq = (int)rint(sqrt(num));

	// deb((sq*sq  == (double) num));

	// return sq * sq == num;
}

void solve() {

	init();

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int acc[n+1];
	acc[0] = 0;

	for (int i = 0; i < n; i++)
		acc[i+1] = acc[i] + a[i];

	int c = 0;

	for (int i = 0; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			if (isPerfectSquare(acc[j] - acc[i]))
				c++;
		}
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