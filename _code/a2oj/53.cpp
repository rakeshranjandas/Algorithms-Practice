#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string s;
	cin >> s;

	string res = "";
	unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'y'};

	for (char x: s) {
		x = tolower(x);
		// deb(x);

		if (vowels.find(x) != vowels.end())
			continue;

		res += '.';
		res += x;
	}

	cout << res;

	return 0;
}