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

	int co = 0;
	map<char, int> mp;
	for (char c: s)
		mp[c]++;

	for (auto x: mp)
		if (x.second & 1)
			co++;

	if (co == 0 || co&1)
		cout << "First";

	else
		cout << "Second";

	return 0;
}