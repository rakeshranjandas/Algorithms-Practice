#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define N 1000001

bool is_comp[N];
int count_primes_till_n[N];

void initSieve() {
	for (int i = 2; i < N; i++) {
		if (is_comp[i])
			continue;

		for (int k = 2; k*i < N; k++)
			is_comp[k*i] = true;
	}

	for (int i = 2; i < N; i++)
		count_primes_till_n[i] = count_primes_till_n[i-1] + (!is_comp[i]);
}

int main() {

	IOS

	initSieve();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << count_primes_till_n[n] << endl;
	}

	return 0;
}