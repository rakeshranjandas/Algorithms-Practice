#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSubseq(int a[], int n) {

	unordered_map<int, int> m;
	int maxChainLength = 0;

	for (int i = 0; i < n; i++)
		m[a[i]] = 1;

	for (auto &x: m) {

		// If already visited, then skip
		if (x.second == 0)
			continue;

		// Check if the number is start of chain
		// If not a start of a chain, then mark it
		// such that it won't be checked again
		if (m.find(x.first - 1) != m.end()) {
			x.second = 0;
			continue;
		}

		// For every start of chain
		int chainLength = 1, start = x.first;

		while (m.find(start + 1) != m.end()) {
			m[start] = 0;
			start++;
			chainLength++;
		}

		maxChainLength = max(chainLength, maxChainLength);
	}

	return maxChainLength;
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

		cout << longestConsecutiveSubseq(a, n) << endl;
	}

	return 0;
}