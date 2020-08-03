#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string isSubset(int a[], int n, int b[], int m) {

	unordered_map<int, int> m_a, m_b;

	for (int i = 0; i < n; i++)
		m_a[a[i]]++;

	for (int i = 0; i < m; i++)
		m_b[b[i]]++;

	for (auto b_c: m_b)
		if (m_a[b_c.first] < b_c.second)
			return "No";

	return "Yes";
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

		cout << isSubset(a, n, b, m) << endl;
	}

	return 0;
}