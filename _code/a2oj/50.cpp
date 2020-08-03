#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int k;
	cin >> k;

	string s;
	cin >> s;

	map<char, int> mp;
	for (char x: s)
		mp[x]++;

	string res = "";
	bool can = true;

	for (auto x: mp) {
		if (x.second % k != 0) {
			can = false;
			break;
		}

		res += string(x.second/k , x.first);
	}

	string ans = res;

	if (can) {

		for (int i = 1; i < k; i++)
			ans += res;
	}

	cout << (can ? ans : "-1");

	return 0;
}