#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
// #define MAX 100
bool a[MAX];
vector<int> primes;

void sieve() {

	for (int i = 2; i*i < MAX; i++) {

		if (a[i])
			continue;

		for (int m = 2*i; m < MAX; m+=i)
			a[m] = true;
	}

	for (int i = 2; i < MAX; i++)
		if (!a[i])
			primes.push_back(i);

	// for (auto p : primes)
	// 	cout << p << " ";
	// cout << endl;
}

long long int primeSum(int n) {

	long long int sum = 0;

	for (int i = 0; i < primes.size() && primes[i] <= n; i++)
		sum += primes[i];

	return sum;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << primeSum(n) << endl;
	}

	return 0;
}