#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define MOD 1000000007

bool allPos(ll a[], int n) {
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			return false;

	return true;
}

bool allNeg(ll a[], int n) {
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			return false;

	return true;
}

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a+n);

	// for (int i = 0; i < n; i++)
	// 	cout << a[i] << endl;
	// cout << endl;

	ll prod = 1;

	if (k == n) {
		for (int i = 0; i < n; i++)
			prod = (prod * a[i]) % MOD;

	} else if (allPos(a, n)) {
		for (int i = 0; i < k; i++)
			prod = (prod * a[n-1-i]) % MOD;

	} else if (allNeg(a, n)) {
		if (k%2 == 1) {
			for (int i = 0; i < k; i++)
				prod = (prod * a[n-1-i]) % MOD;

		} else {
			for (int i = 0; i < k; i++)
				prod = (prod * a[i]) % MOD;
		}

	} else {

		int l = 0, r = n-1;

		if (k%2 == 1) {
			prod = (a[r]) % MOD;
			r--;
			k--;
		}

		while (k > 0) {
			if (a[l]*a[l+1] > a[r]*a[r-1]) {
				prod = (((prod * a[l]) % MOD) * a[l+1]) % MOD;
				l += 2;

			} else {
				prod = (((prod * a[r]) % MOD) * a[r-1]) % MOD;
				r -= 2;
			}

			k -= 2;
		}
	}

	// deb(prod);
	cout << (prod < 0 ? prod + MOD : prod) << endl;

	return 0;
}