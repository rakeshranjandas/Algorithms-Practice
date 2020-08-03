#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int nonRepeating(long long int a[], int n) {

	unordered_map<long long int, int> m;

	for (int i = 0; i < n; i++)
		m[a[i]]++;

	for (int i = 0; i < n; i++)
		if (m[a[i]] == 1)
			return a[i];

	return 0;
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

		long long int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << nonRepeating(a, n) << endl;
	}

	return 0;
}