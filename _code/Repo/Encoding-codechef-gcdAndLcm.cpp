#include<bits/stdc++.h>
#include<iostream>
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
		int n;
		cin >> n;

		unordered_map<long long int, int> m;

		int ip;
		for (int i = 0; i < n; i++) {
			cin >> ip;
			m[ip]++;
		}

		long long int count = 0;
		for (auto x : m) {
			if (m.find(2*x.first) != m.end())
				count += x.second * m[2*x.first];
		}

		cout << count << endl;

	}

	return 0;
}