#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 1000000001

bool sieve[N];
vector<int> primes;

bool canFind(int x, int k) {

	if (x == 1)
		return false;

	if (x < k)
		return false;

	if (k == 1)
		return true;

	if (binary_search(primes.begin(), primes.end(), x))
		return k == 1;

	for (int p: primes) {

		if (p > x)
			return false;

		while (x%p == 0) {
			x = x/p;
			k--;

			if (k == 0)
				return true;
		}
	}

	return false;
}

void initPrimes() {
	for (int i = 2; i < N; i++) {
		if (sieve[i])
			continue;

		primes.push_back(i);

		for (int k = 2; k*i < N; k++) {
			sieve[k*i] = true;
		}
	}

	// for (auto x: primes)
	// 	cout << x << " ";	
}

int main() {

	IOS

	initPrimes();

	int t;
	cin >> t;

	while (t--) {
		int x, k;
		cin >> x >> k;

		cout << canFind(x, k) << endl;
	}

	return 0;
}