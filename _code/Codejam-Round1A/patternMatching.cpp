#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool match(string s1, string s2, int s1i = 0, int s2i = 0, string acc = "") {

	if (s1i == s1.size() || s2i == s2.size()) {
		
		if (s1i == s1.size() && s2i == s2.size())
			return true;

		if (s1[i] == s1.size() && s2[s2i] == '*')
			return true;

		if (s2[i] == s2.size() && s1[s21] == '*')
			return true;

		return false;		
	}


	if (s1[s1i] == '*' && s2[s2i] == '*')
		return match(s1, s2, s1i, s2i+1, acc+"*");

	if (s1[s1i] == '*' && s2[s2i] != '*') {
		
		for (int i = s2.size(); i >= s2i; i--)
			if (match(s1, s2, s1i+1, ))
	}
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		int n;
		cin >> n;

		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		string res_s = s[0];
		for (int i = 1; i < n; i++) {
			res_s = match(res_s, s[i]);
			if (res_s == "")
				break;
		}

		cout << "Case #" << t_i << ": " << (res_s == "" ? "*" : res_s) << endl;
	}

	return 0;
}