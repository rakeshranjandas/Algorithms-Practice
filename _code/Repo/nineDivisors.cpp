// https://practice.geeksforgeeks.org/problems/nine-divisors/0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define MAXM 1000000000001
#define MAXM 100000
#define MAX 500001
bool a[MAX];
// int *a;
// vector<long long int> v;
vector<long long int> nineDiv;

void initialise() {
	// a = (int *) malloc(sizeof(int) * MAX);
	for (int i = 2; i*i < MAX; i++) {

		// Skip non-prime numbers
		if (a[i])
			continue;

		for (int m = 2*i; m < MAX; m += i) {
			a[m] = true;
		}
	}

	// for (int i = 0; i < MAX; i++)
	// 	cout << "(" << i << ")" << a[i] << " ";
	// cout << endl;
 
 	vector<int> primes;

	for (int i = 2; i < MAX; i++) {
		if (!a[i])
			primes.push_back(i);
	}


	// for (auto n: primes)
	// 	cout << n << " ";
	// cout << endl;

	int primesSize = primes.size();

	for (int i = 0; i < primesSize-1; i++) {
		bool flag = false;
		long long int eightPow = (long long int) pow(primes[i], 8);

		cout << "eightPow " << eightPow << endl;

		if (eightPow < MAXM) {
			nineDiv.push_back((long long int) eightPow);
			flag = true;
			cout << " eightPow push " << (long long int) eightPow << endl;
		}

		for (int j = i+1; j < primesSize; j++) {
			long long int primeSquareProduct = (long long int) primes[i]*primes[i] * primes[j]*primes[j];
			cout << " primesQ " << primeSquareProduct << endl;

			if (primeSquareProduct < MAXM) {
				nineDiv.push_back((long long int) primeSquareProduct);
				flag = true;
				cout << " primesQ push" << (long long int) primeSquareProduct << endl;
				continue;
			}

			break;
		}

		if (!flag)
			break;
	}

	sort(nineDiv.begin(), nineDiv.end());

	for (auto n: nineDiv)
		cout << n << " ";
	cout << endl;
}

int nineDivisors(int n) {

	vector<long long int> :: iterator it = lower_bound(nineDiv.begin(), nineDiv.end(), n);
	cout << "XX " << *it << endl;

	int foundIndex = distance(nineDiv.begin(), it);

	if (!binary_search(nineDiv.begin(), nineDiv.end(), n))
		foundIndex--;

	return foundIndex+1;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	initialise();

	int t;
	cin >> t;

	while (t--) {
		long long int n;
		cin >> n;

		cout << nineDivisors(n) << endl;
	}

	return 0;
}