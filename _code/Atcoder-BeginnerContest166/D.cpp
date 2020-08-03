#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

unordered_map<ll, ll> all_five_pows;

void init() {
	ll n = 0, fn = 0;

	while (fn < 100000000000001) {
		fn = n * n * n * n * n;
		all_five_pows[fn] = n;
		n++;
	}
}

bool isPowFive(ll n) {
	return all_five_pows.find(n) != all_five_pows.end();
}

int main() {

	IOS

	init();
	// deb(isPowFive(0));

	// for (auto x: all_five_pows)
	// 	cout << x.first << " " << x.second << endl;

	ll x;
	cin >> x;

	ll a = 0, b, af, bf;

	while (true) {

		af = a * a * a * a * a;
		bf = af - x;

		// deb(af); deb(bf);

		if (isPowFive(abs(bf))) {
			b = all_five_pows[abs(bf)];
			if (bf < 0)
				b *= -1;
			break;
		}

		a++;
	}

	cout << a << " " << b;

	return 0;
}