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
		string s;
		cin >> s;

		int c = 0;
		int max_valid = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<')
				c++;
			else
				c--;

			if (c == 0)
				max_valid = max(max_valid, i+1);

			else if (c < 0)
				break;
		}

		cout << max_valid << endl;
	}

	return 0;
}