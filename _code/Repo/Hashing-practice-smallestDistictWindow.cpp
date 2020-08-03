#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int smallestDistinctWindow(string s) {


	int distinctCharCount = 0;

	int *totalCharCount = (int*) malloc(sizeof(int) * 26);
	memset(totalCharCount, 0, sizeof(int) * 26);

	for (int i = 0; i < s.length(); i++) {
		if (totalCharCount[s[i] - 'a'] == 0)
			distinctCharCount++;
		totalCharCount[s[i] - 'a']++;
	}

	// cout << "---" << distinctCharCount << endl;
	// for (int i = 0; i < 26; i++)
	// 	cout << totalCharCount[i] << " ";
	// cout << endl;

	memset(totalCharCount, 0, sizeof(int) * 26);
	int distChars = 0, windowSize, minWindowSize = s.length(), l = 0;

	for (int r = 0; r < s.length(); r++) {

		if (totalCharCount[s[r] - 'a'] == 0)
			distChars++;

		totalCharCount[s[r] - 'a']++;

		if (distChars == distinctCharCount) {
			while (totalCharCount[s[l] - 'a'] > 1) {
				totalCharCount[s[l] - 'a']--;
				l++;
			}

			windowSize = r - l + 1;
			minWindowSize = min(windowSize, minWindowSize);
		}
	}

	return minWindowSize;
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

		cout << smallestDistinctWindow(s) << endl;
	}

	return 0;
}