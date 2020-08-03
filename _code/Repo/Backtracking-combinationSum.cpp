#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

void printFormattedIfUnique(string str, unordered_set<string> &s) {

	if (s.find(str) == s.end()) {
		cout << "(" << str.substr(1) << ")";	
		s.insert(str);
	}
}

void printCombinationsHelper(int a[], int n, int ind,
	int rem, string str, unordered_set<string> &s, bool *has_more_than_one) {

	if (rem == 0) {
		*has_more_than_one = true;
		printFormattedIfUnique(str, s);
		return;
	}

	if (ind >= n)
		return;

	if (rem < 0)
		return;

	for (int i = ind; i < n; i++) {
		string new_str = str + " " + to_string(a[i]);
		printCombinationsHelper(a, n, i, rem-a[i], new_str, s, has_more_than_one);
	}
}

void printCombinations(int a[], int n, int b) {

	sort(a, a+n);
	string str = "";
	unordered_set<string> s;
	bool has_more_than_one = false;

	printCombinationsHelper(a, n, 0, b, str, s, &has_more_than_one);

	if (!has_more_than_one)
		cout << "Empty";
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

		int b;
		cin >> b;

		printCombinations(a, n, b);
		cout << endl;
	}

	return 0;
}