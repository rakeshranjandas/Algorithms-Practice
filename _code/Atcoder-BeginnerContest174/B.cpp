#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

ll distSq(ll x, ll y) {
	return x*x + y*y;
}

int main() {

	IOS

	ll n, d;
	cin >> n >> d;

	ll c = 0, x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		if (distSq(x, y) <= d*d)
			c++;
	}

	cout << c << endl;

	return 0;
}