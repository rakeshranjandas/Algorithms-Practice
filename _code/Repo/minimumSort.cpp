#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printPairArr(pair<int, int> p[], int n) {
	for (int i = 0; i < n; i++)
		cout << p[i].first << "(" << p[i].second << ") - ";

	cout << endl;
}

int minSortCount(int a[], int n) {

	pair<int, int> pairArr[n];

	for (int i = 0; i < n; i++) {
		pairArr[i].first = a[i];
		pairArr[i].second = i;
	}

	sort(pairArr, pairArr+n);

	// printPairArr(pairArr, n);

	// Initialise visited array
	bool vis[n];
	memset(vis, false, sizeof(bool) * n);

	int count = 0;

	for (int i = 0; i < n; i++) {

		// If prev position is same as now OR already visited, skip
		if (pairArr[i].second == i || vis[i])
			continue;

		int nextNode = pairArr[i].second, cycleSize = 1;

		while (nextNode != i) {
			// cout << nextNode << "next\n";

			vis[nextNode] = true;
			nextNode = pairArr[nextNode].second;
			cycleSize++;
		}

		// cout << "cycleSize " << cycleSize << endl;
		count += cycleSize - 1;
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

		cout << minSortCount(a, n) << endl;
	}

	return 0;
}