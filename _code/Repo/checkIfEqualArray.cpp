#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int checkIfEqual(long long int a[], long long int b[], int n) {

	unordered_map<long long int, int> m;

	for (int i = 0; i < n; i++)
		m[a[i]]++;

	for (int i = 0; i < n; i++) {

		if (m.find(b[i]) != m.end()) {

			if (m[b[i]] == 0)
				return 0;

			m[b[i]]--;

		} else {
			return 0;
		}
	}

	return 1;
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
		
		long long int b[n];
		for (int i = 0; i < n; i++)
			cin >> b[i];

		cout << checkIfEqual(a, b, n) << endl;
	}

	return 0;
}