#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void kFrequency(int a[], int n, int k) {

	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[a[i]]++;

	vector<int> v;

	for (auto mm: m)
		if (mm.second == k)
			v.push_back(mm.first);

	if (v.size() > 0) {
		sort(v.begin(), v.end());
		for (auto num: v)
			cout << num << " ";

	} else
		cout << "-1";

	cout << endl;
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

		kFrequency(a, n, k);
	}

	return 0;
}