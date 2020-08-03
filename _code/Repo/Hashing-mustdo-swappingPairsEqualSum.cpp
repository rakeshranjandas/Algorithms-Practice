#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canMakeSumEqualBySwap(int a[], int n, int b[], int m) {
	
	unordered_set<int> set_a, set_b;
	int sumA = 0, sumB = 0;

	for (int i = 0; i < n; i++) {
		set_a.insert(a[i]);
		sumA += a[i];
	}

	for (int i = 0; i < m; i++) {
		set_b.insert(b[i]);
		sumB += b[i];
	}

	if (abs(sumA - sumB) % 2 > 0)
		return false;

	for (auto  x: set_a) {
		int toFind = x - ((sumA - sumB) / 2);

		if (set_b.find(toFind) != set_b.end())
			return true;
	}

	return false;
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
		int n, m;
		cin >> n >> m;

		int a[n], b[m];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < m; i++)
			cin >> b[i];

		cout << (canMakeSumEqualBySwap(a, n, b, m) ? "1" : "-1") << endl;
	}

	return 0;
}