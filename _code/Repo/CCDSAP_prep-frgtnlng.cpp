#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

		string a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		unordered_set<string> s;
		int ki;
		string inp;

		for (int i = 0; i < k; i++) {
			cin >> ki;

			for (int i = 0; i < ki; i++) {
				cin >> inp;
				s.insert(inp);
			}
		}

		for (int i = 0; i < n; i++)
			cout << (s.find(a[i]) != s.end() ? "YES" : "NO") << " ";

		cout << endl;
	}

	return 0;
}