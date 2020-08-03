#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool isPrime(ll n) {
	if (n == 1)
		return false;

	for (ll i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}

bool isSqOfPrime(ll n) {
	fesetround(FE_DOWNWARD);
	ll x = lrint(sqrt(n));
	return x*x == n && isPrime(x);
}

int main() {

	IOS

	int n;
	cin >> n;

	ll x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cout << (isSqOfPrime(x) ? "YES" : "NO") << endl;
	}

	return 0;
}