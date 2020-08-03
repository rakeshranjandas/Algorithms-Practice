#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

// A function to print all prime 
// factors of a given number n 
bool primeFactors(int n, int k) 
{ 
	// Print the number of 2s that divide n 
	while (n % 2 == 0) 
	{ 
		// cout << 2 << " ";
		k--; 
		n = n/2; 
	}

	if (k <= 0)
		return true;

	// n must be odd at this point. So we can skip 
	// one element (Note i = i +2) 
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		// While i divides n, print i and divide n 
		while (n % i == 0) 
		{ 
			// cout << i << " ";
			k--;
			if (k <= 0)
				return true;
			n = n/i; 
		} 
	} 

	// This condition is to handle the case when n 
	// is a prime number greater than 2 
	if (n > 2) {
		// cout << n << " ";
		k--;
		if (k <= 0)
			return true;
	}

	return false;
} 

/* Driver code */
// int main() 
// { 
// 	int n = 99999999; 
// 	primeFactors(n); 
// 	return 0; 
// } 

// This is code is contributed by rathbhupendra 

int main() {

	IOS

	// initPrimes();

	int t;
	cin >> t;

	while (t--) {
		int x, k;
		cin >> x >> k;

		cout << primeFactors(x, k) << endl;
	}

	return 0;
}
