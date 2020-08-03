#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef map<char, int> mci;

void printMap(mci mp) {
	for (auto x: mp)
		cout << x.first << " " << x.second << endl;
}

string init(int a, int b, mci &char_count) {

	string s = "";
	int i = 0;

	for (; i < b; i++)
		s += 'a' + i;

	i--;

	for (int j = b; j < a; j++)
		s += 'a' + i;

	for (char c: s)
		char_count[c]++;

	return s;
}

string build(int n, int a, int b) {

	mci char_count;

	string s = init(a, b, char_count);
	// deb(s);
	// printMap(char_count);

	for (int i = 0; i < n-a; i++) {
		char_count[s[i]]--;

		if (char_count[s[i]] == 0) {
			s += s[i];
			char_count[s[i]]++;

		} else {
			s += 'a';
			char_count['a']++;
		}
	}

	return s;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		cout << build(n, a, b) << endl;
	}

	return 0;
}
