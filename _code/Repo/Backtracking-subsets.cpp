#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

void printMultiset(multiset<int> ms) {

	cout << "(";
	for (auto x: ms)
		cout << x << ",";
	cout << ") ";
}

void printVector(vector<int> &v) {
	cout << "(";
	for (auto x: v)
		cout << x << ",";
	cout << ") ";
}

void printVector(vector<string> &v) {
	for (auto x: v)
		cout << "(" << x << ")";
	cout << endl;
}

void printSet(unordered_set<string> &v) {
	for (auto x: v)
		cout << "<" << x << ">";
	cout << endl;
}

void printSubsetHelper(int a[], int n, int now, unordered_set<string> &us, string str) {

	if (us.find(str) == us.end()) {
		cout << "(" << (str.size() > 0 ? str.substr(1) : "") << ")";
		us.insert(str);
	}

	if (now == n) {
		return;
	}

	for (int i = now; i < n; i++) {
		string new_str = str + " " + to_string(a[i]);
		printSubsetHelper(a, n, i+1, us, new_str);
	}
}

void printAllSubsets(int a[], int n) {
	sort(a, a+n);

	string str = "";
	unordered_set<string> us;

	printSubsetHelper(a, n, 0, us, str);
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

		printAllSubsets(a, n);
		cout << endl;
	}

	return 0;
}