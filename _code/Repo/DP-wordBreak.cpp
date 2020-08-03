#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool canBreak(string str, unordered_set<string> dict) {


	if (!str.size())
		return true;

	bool ret = false;

	for (int i = 1; i <= str.size(); i++) {
		if (!ret && dict.find(str.substr(0, i)) != dict.end())
			ret |= canBreak(str.substr(i), dict);
	}

	return ret;
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
		string ip;
		for (int i = 0; i < n; i++) {
			cin >> ip;
			dict.insert(ip);
		}

		string str;
		cin >> str;

		cout << canBreak(str, dict) << endl;

		// string ss = "Hello";
		// cout << (ss.substr(5)).size() << endl;
	}

	return 0;
}