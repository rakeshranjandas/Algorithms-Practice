#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string h;
	getline(cin, h);
	map<char, int> mph;
	for (char x: h)
		mph[x]++;

	string s;
	getline(cin, s);	
	map<char, int> mps;
	for (char x: s)
		mps[x]++;

	bool can = true;

	for (auto v: mps) {
		if (v.first == ' ')
			continue;

		if (mph[v.first] < v.second) {
			can = false;
			break;
		}
	}

	cout << (can ? "YES" : "NO");

	return 0;
}