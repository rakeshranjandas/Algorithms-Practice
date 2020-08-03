#include <iostream>
#include <bits/stdc++.h>
using namespace std;  

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif
		
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s[n];
		map<char, int> m;

		for (int i =0; i < n; i++)
			cin >> s[i];

		for (int i = 0; i < n; i++) {
			for (char ch : s[i]) {

				// cout << ch << "<" << endl;
				switch(ch) {
					case 'c':
					case 'o':
					case 'd':
					case 'e':
					case 'h':
					case 'f':
						m[ch]++;

						break;
				}
			}
		}

		int count = INT_MAX;
		for (auto x : m) {
			cout << x.first << "_" << x.second << endl;

			if (x.first == 'c' || x.first == 'e')
				count = min(x.second / 2, count);
			else 
				count = min(x.second, count);
		}

		cout << count << endl;
	}

	return 0;
}