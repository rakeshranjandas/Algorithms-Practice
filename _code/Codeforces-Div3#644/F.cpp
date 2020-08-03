#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int diffCount(string &s1, string &s2) {
	int dc = 0;
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] != s2[i])
			dc++;

	return dc;
}

void generateAllStrings(vector<string> &v, string s, int pos) {

	if (pos == s.size())
		return;

	string dups = s;

	for (char c = 'a'; c <= 'z'; c++) {
		dups[pos] = c;
		v.push_back(dups);
	}

	generateAllStrings(v, s, pos+1);
}

 

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		vector<string> all_strings;
		generateAllStrings(all_strings, s[0], 0);

		bool can;
		string res;

		for (auto st: all_strings) {
			res = st;
			can = true;

			for (int i = 0; i < n; i++)	{
				if (diffCount(res, s[i]) > 1) {
					can = false;
					break;
				}
			}

			if (can)
				break;
		}

		cout << (can ? res : "-1") << endl;
	}

	return 0;
}