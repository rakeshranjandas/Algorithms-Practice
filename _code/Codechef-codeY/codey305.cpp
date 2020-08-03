#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

string findWord(string &s, int i) {
	string new_word = "";
	while (i < s.size() && s[i] != ' ')
		new_word += s[i++];

	return new_word;
}

char upperCase(char c)  {
	return c >= 'a' && c <= 'z' ? c-'a'+'A' : c;
}

bool caseInsensitiveEqual(string s1, string s2) {
	if (s1.size() != s2.size())
		return false;

	for (int i = 0; i < s1.size(); i++) {
		// cout << (upperCase(s1[i]) !=	upperCase(s2[i])) << "--\n";

		// deb((upperCase(s1[i])));
		if (upperCase(s1[i]) !=	upperCase(s2[i]))
			return false;
	}

	return true;
}

string whitespace(int n) {
	string s = "";
	for (int i = 0; i < n; i++)
		s += " ";
	return s; 	
}

string sanitized(string &s) {

	int i = 0;
	string modified_s = "", last_word = "";
	int ws = 0;

	while (true) {

		while (i < s.size() && s[i] == ' ') {
			i++;
			ws++;
		}

		if (i == s.size())
			break;

		string word = findWord(s, i);
		i += word.size();

		if (!caseInsensitiveEqual(word, last_word)) {
			modified_s += whitespace(ws) + word;
			last_word = word;
		}

		ws = 0;
		// deb(word);
	}
	
	return modified_s + whitespace(ws);
}

int main() {

	IOS

	int t;
	cin >> t;
	cin.ignore();

	while (t--) {
	    string s;
	    getline(cin, s);
	    cout << sanitized(s) << endl;
	}

	return 0;
}