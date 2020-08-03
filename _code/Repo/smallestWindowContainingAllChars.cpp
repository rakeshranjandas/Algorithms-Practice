#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printHash(map<char, int> m) {
	for (auto x : m)
		cout << " " << x.first << ":" << x.second << ", ";
	cout << endl;
}

string smallestWindow(string t, string p) {
	string res = "-1";

	if (t.length() < p.length())
		return res;

	map<char, int> hash_p, hash_t;

	// Create hash map of pattern
	for (auto x : p)
		hash_p[x]++;

	// printHash(hash_p);

	int foundLength = 0, start = 0,
		minLength = INT_MAX, windowLength, minLengthStart;

	// Iterate over text
	for (int i = 0; i < t.length(); i++) {
		if (hash_p.find(t[i]) != hash_p.end()) {
			hash_t[t[i]]++;

			if (hash_t[t[i]] <= hash_p[t[i]])
				foundLength++;
		}

		if (foundLength == p.length()) {

			// Check if window can be minimised
			// start slides left when
			// start char is not present in pattern, or
			// start char is an excess
			while (true) {
				// cout << "i " << i << " start " << start << endl;
				// printHash(hash_p);
				// printHash(hash_t);

				if (hash_p.find(t[start]) == hash_p.end())
					start++;

				else if (hash_t[t[start]] > hash_p[t[start]]) {
					hash_t[t[start]]--;
					start++;

				} else
					break;
			}

			windowLength = i - start + 1;
			// cout << "windowLength " << windowLength  
				// << " start " << start << " i" << i << endl;
			if (windowLength < minLength) {
				minLength = windowLength;
				minLengthStart = start;
			}
		}
	}

	// cout << start << " X " << minLength << endl;

	if (foundLength == p.length())
		res = t.substr(minLengthStart, minLength);

	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;

	while (t--) {
		// string s1, s2;
		// cin >> s1 >> s2;

		cout << smallestWindow("timetopractice", "toc") << endl;
	}
}