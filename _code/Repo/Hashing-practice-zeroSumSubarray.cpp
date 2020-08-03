#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countZeroSumSubarrays(int a[], int n) {
	unordered_map<int, int> m;
	m[0] = 1;

	int runningSum = 0;

	for (int i = 0; i < n; i++) {
		runningSum += a[i];
		m[runningSum]++;
	}

	int count = 0;

	for (auto x: m) {
		// cout << x.first << "(" << x.second << "), " << endl;
		count += (x.second * (x.second - 1)) / 2;
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

		cout << countZeroSumSubarrays(a, n) << endl;
	}

	return 0;
}