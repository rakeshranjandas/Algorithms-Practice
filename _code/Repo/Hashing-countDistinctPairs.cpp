#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countDistinctPairs(int a[], int n, int k) {
	unordered_map<int, int> m;
	unordered_map<int, int> :: iterator it;

	for (int i = 0; i < n; i++)
		m[a[i]]++;


	int count = 0;

	if (k == 0) {
		// All the elements having more than one occurence;
		for (auto mm: m)
			if (mm.second > 1)
				count++;

	} else {

		for (auto mm: m) {
			it = m.find(k+mm.first);

			if (it != m.end()) {
				count++;
			}
		}

	}

	return count;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

		cout << countDistinctPairs(a, n, k) << endl;
	}

	return 0;
}