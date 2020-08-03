#include<iostream>
#include<bits/stdc++.h>
using namespace std;

map<int, vector<char>> m = {
	{2, {'a', 'b', 'c'}},
	{3, {'d', 'e', 'f'}},
	{4, {'g', 'h', 'i'}},
	{5, {'j', 'k', 'l'}},
	{6, {'m', 'n', 'o'}},
	{7, {'p', 'q', 'r', 's'}},
	{8, {'t', 'u', 'v'}},
	{9, {'w', 'x', 'y', 'z'}}
};

void findPossibleWords(int a[], int n, int level, string s = "") {

	// If last level, print the word
	if (level == n) {
		cout << s << " ";
		return;
	}

	for (auto x: m[a[level]]) {
		findPossibleWords(a, n, level+1, s+x);
	}
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

		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		findPossibleWords(a, n, 0);
		cout << endl;
	}

	return 0;
}