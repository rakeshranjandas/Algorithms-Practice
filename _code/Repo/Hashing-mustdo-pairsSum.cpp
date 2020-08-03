#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printPairsWithSum(int a[], int n, int b[], int m, int k) {

	unordered_set<int> s;

	for (int i = 0; i < m; i++)
		s.insert(b[i]);

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
		if (s.find(k-a[i]) != s.end())
			v.push_back({a[i], k-a[i]});

	if (v.size() == 0)
		cout << "-1";

	else {
		sort(v.begin(), v.end());
		cout << v[0].first << " " << v[0].second;

		for (int i = 1; i < v.size(); i++)
			cout << ", " << v[i].first << " " << v[i].second;
	}

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
		int n, m, k;
		cin >> n >> m >> k;

		int a[n], b[m];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < m; i++)
			cin >> b[i];

		printPairsWithSum(a, n, b, m, k);
	}

	return 0;
}