#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Initialize
	long long int fib[101];

	long long int a, b;
	cin >> a >> b;

	// Create sequence
	fib[0] = a;
	fib[1] = b;
	long long int c;
	int fib_size = 101;

	for (int i = 2; i < 101; i++) {
		c = fib[i-1] + fib[i-2];

		// Handle overflow
		if (c < fib[i-2]) {
			fib_size = i;
			break;

		} else
			fib[i] = c;
	}

	int q;
	cin >> q;

	long long int x;

	while (q--) {
		cin >> x;
		cout << (fib[0] == x || fib[1] == x || binary_search(fib+2, fib+fib_size, x) ? "YES" : "NO") << endl;
	}

	return 0;
}