#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestZeroSumLength(int a[], int n) {

	unordered_map<int, pair<int, int>> m;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];

		if (m.find(sum) != m.end()) {
			if (i > m[sum].second)
				m[sum].second = i;

		} else {
			m[sum] = {i, i};
		}
	}

	int maxLen = 0;
	for (auto x: m)
		maxLen = max(maxLen, (x.second.second - x.second.first));

	return maxLen;
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

		cout << largestZeroSumLength(a, n) << endl;
	}

	return 0;
}