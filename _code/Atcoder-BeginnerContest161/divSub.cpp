#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

ll countDiv(ll n) {
	if (n == 1)
		return 0;

	ll cnt = 1;	// n is a divisor. We have to count all divisors not 1
	for (ll i = 2; i*i <= n; i++) {

		if (i*i == n)
			cnt ++;
		else if (n%i == 0)
			cnt += 2;
	}

	return cnt;
}

bool reduced(ll n, ll i) {
	while (n%i == 0)
		n /= i;

	return n % i == 1;
}

int main() {

	IOS

	ll n;
	cin >> n;

	ll m = n-1;

	ll cnt = 1;
	cnt += countDiv(m);

	for (ll i = 2; i*i <= n; i++) {
		if (i*i == n)
			cnt++;

		else if (n%i == 0) {
			if (reduced(n, i))
				cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}