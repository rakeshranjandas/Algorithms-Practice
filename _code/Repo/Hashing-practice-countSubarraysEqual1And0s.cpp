#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int *runningSum;

int subarraysEqual01s(int a[], int n) {

	runningSum = (int *) calloc(n+1, sizeof(int));

	for (int i = 0; i < n; i++)
		runningSum[i+1] = runningSum[i] + (a[i] == 0 ? -1 : 1);

	// cout << "runningSum ";
	// for (int i = 0; i < n+1; i++)
	// 	cout << runningSum[i] << " ";
	// cout << endl;

	unordered_map<int, int> m;
	for (int i = 0; i < n+1; i++)
		m[runningSum[i]]++;

	// for (auto x: m)
	// 	cout << x.first << "(" << x.second << "), ";
	// cout << endl;

	int count = 0;
	for (auto x: m)
		count += (x.second * (x.second - 1)) / 2;



	free(runningSum);
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

		cout << subarraysEqual01s(a, n) << endl;
	}

	return 0;
}