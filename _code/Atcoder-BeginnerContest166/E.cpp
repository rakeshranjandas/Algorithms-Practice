#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	ll n;
	cin >> n;

	ll h[n+1];
	for (ll i = 1; i <= n; i++)
		cin >> h[i];

	ll c = 0;
	map<ll, ll> iAi;
	for (ll i = 1; i <= n; i++) {
		c += iAi[i-h[i]];
		iAi[i+h[i]]++;
	}

	cout << c << endl;

	return 0;
}