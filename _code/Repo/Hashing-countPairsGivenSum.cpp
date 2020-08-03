#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countPairsOfSum(int a[], int n, int k) {
	
	unordered_map<int, int> m;
	unordered_map<int, int> :: iterator it;

	for (int i = 0; i < n; i++)
		m[a[i]]++;

	int c = 0;

	for (auto mm: m) {

		int rest = k - mm.first;

		// If the sum is twice of this number
		if (rest == mm.first) {
			if (mm.second > 1) {
				c += (mm.second * (mm.second-1)) / 2;
			}

		} else {

			it = m.find(rest);

			if (m.find(rest) != m.end()) {
				
				// If has been already parsed
				if (it->second == 0)
					continue;

				c += (mm.second * it->second);
				it->second = 0;
			}
		}

		// cout << mm.first << " " << c << "--" << endl;
	}

	return c;
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
		int n, k;
		cin >> n >> k;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << countPairsOfSum(a, n, k) << endl;
	}

	return 0;
}