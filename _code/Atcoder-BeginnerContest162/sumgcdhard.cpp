#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define M 1000000007

typedef long long int ll;

ll modMult(ll a, ll b) {
	return (a*b) % M;
}

ll modPow(ll base, ll exp) {
	ll res = 1;
	
	while (exp > 0) {
		if (exp & 1)
			res = modMult(res, base);

		exp >>= 1;
		base = modMult(base, base);
	}

	return res;
}

ll modSub(ll a, ll b) {
	return (a - b + M) % M;
}

ll modAdd(ll a, ll b) {
	return (a + b) % M;
}

int main() {

	IOS

	ll n, k;
	cin >> n >> k;

	ll c[k+1];

	for (int i = k; i > 0; i--) {
		ll count_multiples = k / i;
		ll arrangement_with_multiples = modPow(count_multiples, n);

		for (int j = 2*i; j <= k; j += i)
			arrangement_with_multiples = modSub(arrangement_with_multiples, c[j]);

		c[i] = arrangement_with_multiples;
	}

	ll ans = 0;
	for (int i = 1; i <= k; i++)
		ans = modAdd(ans, modMult(i, c[i]));

	cout << ans;

	return 0;
}