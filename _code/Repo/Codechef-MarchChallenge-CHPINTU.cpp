#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

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

		int f[n];
		for (int i = 0; i < n; i++)
			cin >> f[i];

		int p[n];
		for (int i = 0; i < n; i++)
			cin >> p[i];

		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
			mp[f[i]] += p[i];

		int minm = INT_MAX;
		for (auto x: mp)
			minm = min(minm, x.second);

		cout << minm << endl;
	}

	return 0;
}