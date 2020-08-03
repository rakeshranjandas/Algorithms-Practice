#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findDistinctElementsCount(vector<vector<int>> v, int n) {

	unordered_set<int> s;
	unordered_set<int> :: iterator it;

	// Save first row in a set
	for (int i = 0; i < n; i++)
		s.insert(v[0][i]);

	// for (auto i: s)
	// 	cout << i << " ";

	for (int i = 1; i < n; i++){
		sort(v[i].begin(), v[i].end());

		for (it = s.begin(); it != s.end(); it++) {
			if (!binary_search(v[i].begin(), v[i].end(), *it)) {
				s.erase(*it);
				// cout << *it;
			};
		}

	}

	return s.size();
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

		vector<vector<int>> v;
		int ip;

		for (int i = 0; i < n; i++) {
			vector<int> vi;

			for (int j = 0; j < n; j++) {
				cin >> ip;
				vi.push_back(ip);
			}

			v.push_back(vi);
		}

		cout << findDistinctElementsCount(v, n) << endl;
	}

	return 0;
}