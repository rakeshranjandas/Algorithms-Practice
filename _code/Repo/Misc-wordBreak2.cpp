#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

void findPossible(string str, int cur_ind, string upto_str, string now_str,
	set<string> &res_set, unordered_set<string> &dict) {

	if (cur_ind == str.size()) {
		if (now_str == "")
			res_set.insert(upto_str.substr(1));

		return;
	}

	string new_str = now_str + str[cur_ind];

	if (dict.find(new_str) != dict.end())
		findPossible(str, cur_ind+1, (upto_str + " " + new_str), "", res_set, dict);

	findPossible(str, cur_ind+1, upto_str, new_str, res_set, dict);
}

void printSet(set<string> res_set) {
	for (auto x: res_set)
		cout << "(" << x << ")";
}

void printPossible(string str, unordered_set<string> dict) {

	set<string> res_set;
	findPossible(str, 0, "", "", res_set, dict);

	printSet(res_set);
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

		unordered_set<string> dict;
		string d_str;

		for (int i = 0; i < n; i++) {
			cin >> d_str;
			dict.insert(d_str);
		}

		string str;
		cin >> str;

		printPossible(str, dict);
		cout << endl;
	}

	return 0;
}