#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 1000000000000
// #define N 100

vector<int> genPrimes() {
	int NN = 1000002;
	vector<int> primes;
	bool is_comp[NN] = {0};

	for (int i = 2; i < NN; i++) {
		if (is_comp[i])
			continue;

		primes.push_back(i);

		for (int j = 2; i*j < NN; j++)
			is_comp[i*j] = true;
	}

	return primes;
}

vector<int> findPrimeExponents(ll n) {
	vector<int> pe;
	ll nn = n;

	vector<int> primes = genPrimes();

	// for (int x: primes)
	// 	cout << x << " ";

	// cout << endl;

	// return pe;

	for (int j = 0; (ll) primes[j] * primes[j] <= nn; j++) {

		int i = primes[j];
		int e = 0;

		while (n > 1 && n % i == 0) {
			e++;
			n = n/i;
		}

		if (e > 0)
			pe.push_back(e);

		if (n < i)
			break;
	}

	return pe;
}

vector<ll> generateAllAP() {
	vector<ll> ap;
	ll sum = 0;

	for (int i = 1; sum <= N; i++) {
		ap.push_back(sum += i);
	}

	return ap;
}

int main() {

	IOS

	ll n;
	cin >> n;

	if (n == 1) {
		cout << 0 << endl;

	} else {

		vector<int> pe = findPrimeExponents(n);

		if (pe.size() == 0) {
			cout << 1 << endl;

		} else {

			vector<ll> all_ap = generateAllAP();
			ll res = 0;
			
			for (int x: pe) {

				// deb(x);
				res += distance(all_ap.begin(), upper_bound(all_ap.begin(), all_ap.end(), (ll)x) - 1) + 1;

				// deb((upper_bound(all_ap.begin(), all_ap.end(), x) - 1));

				// deb();
			}

			cout << res << endl;
			// deb(res);


			// for (int x: all_ap)
			// 	cout << x << " ";
			// cout << endl;
		}

		// for (int x: pe)
		// 	cout << x << " ";
		// cout << endl;
	}

	return 0;
}