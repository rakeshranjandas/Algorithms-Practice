#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int occurKTimes(int a[], int n, int k) {

	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[a[i]]++;

	for (int i = 0; i < n; i++)
		if (m[a[i]] == k)
			return a[i];

	return -1;
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

		cout << occurKTimes(a, n, k) << endl;
	}

	return 0;
}