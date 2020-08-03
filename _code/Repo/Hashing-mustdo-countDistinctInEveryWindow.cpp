#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string distinctInWindowCount(int a[], int n, int k) {

	unordered_map<int, int> m;
	string res = "";
	int distCount = 0;

	for (int i = 0; i < k; i++) {
		m[a[i]]++;
		if (m[a[i]] == 1)
			distCount++;
	}

	res += to_string(distCount);

	for (int i = 1; i <= n-k; i++) {

		if (--m[a[i-1]] == 0)
			distCount--;

		if (++m[a[i+k-1]] == 1)
			distCount++;
		
		res += " " + to_string(distCount);
	}

	return res;
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

		cout << distinctInWindowCount(a, n, k) << endl;
	}

	return 0;
}