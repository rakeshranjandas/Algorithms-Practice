#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string sumExists(int a[], int n, int k) {
	
	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[a[i]]++;

	for (auto mm: m) {
		int rest = k - mm.first;

		// If the sum is twice of this number
		if (rest == mm.first) {
			if (mm.second > 1)
				return "Yes";

		} else {
			if (m.find(rest) != m.end())
				return "Yes";
		}
	}

	return "No";
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

		cout << sumExists(a, n, k) << endl;
	}

	return 0;
}