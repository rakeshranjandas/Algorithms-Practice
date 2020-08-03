#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 10000001
vector<int> superPrimes;

void generateSieve() {
    bool *a = (bool *) malloc(MAX * sizeof(bool));

	for (int i = 2; i*i < MAX; i++) {
		if (a[i])
			continue;

		for (int m = i+i; m < MAX; m += i) {
// 			cout << "m " << m << endl;
			a[m] = true;
		}
	}

	for (int i = 3; i+2 < MAX; i++) {
// 		cout << '(' << i << ')' << a[i] << ' ';

		if (a[i] == 0 && a[i+2] == 0)
			superPrimes.push_back(i+2);
	}
// 	cout << endl;

// 	for (auto x: superPrimes)
// 		cout << x << " ";
// 	cout << endl;
}

int countSuperPrimes(int n) {
	vector<int> :: iterator it = 
	lower_bound(superPrimes.begin(), superPrimes.end(), n);
// 	cout << *it << "<<--" << endl;
    int dist = distance(superPrimes.begin(), it);
    
    if (binary_search(superPrimes.begin(), superPrimes.end(), n))
        dist++;
	return dist;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	generateSieve();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << countSuperPrimes(n) << endl;
		// cout << isPrime(n) << endl;
	}

	return 0;
}