#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkFrequencies(string s) {

	unordered_map<char, int> m;

	for (int i = 0; i < s.size(); i++)
		m[s[i]]++;

	// If only one character is present throughout
	if (m.size() == 1)
		return true;

	map<int, int> map_length;

	for (auto x: m)
		map_length[x.second]++;

	// for (auto x: map_length)
	// 	cout << x.first << "(" << x.second << "), ";
	// cout << endl;

	if (map_length.size() == 1 || map_length.size() == 2) {

		// If all char counts is equal
		if (map_length.size() == 1)
			return true;

		else {
			auto first_pair = map_length.rbegin();
			auto second_pair = ++map_length.rbegin();

			// cout << "first " << first_pair->first << "(" << first_pair->second << "), ";
			// cout << "second " << second_pair->first << "(" << second_pair->second << "), ";

			if (second_pair->first == 1 && second_pair->second == 1)
				return true;

			else if (first_pair->first == second_pair->first+1 && first_pair->second == 1)
				return true;
		}
	}

	return false;
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
		string s;
		cin >> s;

		cout << (checkFrequencies(s) ? 1 : 0) << endl;
	}

	return 0;
}