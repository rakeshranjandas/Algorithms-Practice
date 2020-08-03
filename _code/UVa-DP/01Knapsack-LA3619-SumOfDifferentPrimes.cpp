#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 1121
#define K 15

vector<int> primes;
int PRIMES_SIZE;

int ways[N][K];
int n, k;

void solve() {
	memset(ways, 0, sizeof(ways));

	for (int pi = 0; pi < PRIMES_SIZE; pi++) {
		for (int ki = k-1; ki > 0; ki--) {
			for (int num = 1; num < N; num++) {
				if (num + primes[pi] >= N)
					continue;

				if (ways[num][ki])
					ways[num + primes[pi]][ki+1] += ways[num][ki];
			}
		}

		ways[primes[pi]][1]++;
	}

	cout << ways[n][k] << endl;
}

void init() {
	bool comp[N] = {0};
	for (int i = 2; i < N; i++) {
		if (comp[i])
			continue;

		primes.push_back(i);

		for (int k = 2; i*k < N; k++)
			comp[i*k] = true;
	}

	PRIMES_SIZE = primes.size();
}

int main() {

	IOS

	init();

	while (true) {
		cin >> n >> k;
		if (!n && !k)
			break;
		solve();
	}

	return 0;
}