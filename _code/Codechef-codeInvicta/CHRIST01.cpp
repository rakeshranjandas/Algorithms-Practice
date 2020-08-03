#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define M 1000000007

#define NK 260001
ll factorial[NK];

void initFact() {
	factorial[0] = factorial[1] = 1;
	for (int i = 2; i < NK; i++)
		factorial[i] = (factorial[i-1] * i) % M;
}

ll fact(ll n) {
	return factorial[n];
}

ll modular_pow(ll base, ll exp) {
	ll res = 1;

	while (exp > 0) {
		if (exp & 1)
			res = (res * base) % M;

		exp >>= 1;
		base = (base * base) % M;
	}

	return res;
}

ll mod_inv(int a) {
	return modular_pow(a, M-2);
}

ll comb(ll n, ll r) {
	return (fact(n) * mod_inv((fact(r) * fact(n-r)) % M )) % M;
}

int ways(int n, int k) {

	ll ans = 0, temp;

	for (int i = 1; i <= n; i++) {
		temp = comb(n, i);
		temp = (temp * fact(n*k - i*k + i)) % M;
		temp = (temp * mod_inv(modular_pow(fact(k), n-i))) % M;
		
		if (i%2 == 1)
			ans = (ans + temp) % M;
		else
			ans = (ans - temp + M) % M;
	}

	return ans;
}

int main() {

	FILE_WR
	IOS

	initFact();

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		cout << ways(n, k) << endl;
	}

	return 0;
}