#include<iostream>
#include<bits/stdc++.h>
using namespace std;

set<string> result_set;

void combinationSum(int a[], int index, int size, int rem, string s) {

	if (rem < 0)
		return;

	if (rem == 0) {
		result_set.insert(s);
		return;
	}

	for (int i = index+1; i < size; i++) {
		combinationSum(a, i, size, rem-a[i], (s == "" ? "" : s + " ") + to_string(a[i]));
	}
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

		int k;
		cin >> k;

		sort(a, a+n);

		result_set.clear();
		
		combinationSum(a, -1, n, k, "");

		if (result_set.size())
			for (auto x: result_set)
				cout << "(" << x << ")";
		else
			cout << "Empty";

		cout << endl;
	}

	return 0;
}