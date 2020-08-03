#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subarrayWithSum(int a[], int n, int k) {

	unordered_map<int, pair<int, int>> m;

	int sum = 0;
	m[0] = {0, 0};
	for (int i = 0; i < n; i++) {
		sum += a[i];
		m[sum] = { 
			(m[sum].first > 0 ? (min(m[sum].first, i+1)) : i+1),	// Min index occurence
			max(m[sum].second, i+1) 								// Max index occurence
		};


	}

	// for (auto x: m)
	// 	cout << x.first << "(" << x.second.first << "," << x.second.second << "), ";
	// cout << endl;

	int maxSubArrLength = 0, subArrLength, toSearch;

	for (auto x: m) {
		toSearch = k + x.first;
		// cout << "Now " << x.first << " , Searching " << toSearch << endl;

		if (m.find(toSearch) != m.end()) {
			subArrLength = m[toSearch].second - x.second.first;
			maxSubArrLength = max(maxSubArrLength, subArrLength);

			// cout << "Found " << m[toSearch].first << ", " << m[toSearch].second << endl;
			// cout << "sublen " << subArrLength << endl;
			// cout << "MAx sublen " << maxSubArrLength << endl;
		}
	}

	return maxSubArrLength;
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

		cout << subarrayWithSum(a, n, k) << endl;
	}

	return 0;
}