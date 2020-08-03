#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	string ip;
	cin >> ip;

	int cl = 0;

	for (auto c: ip)
		if (c >= 'a' && c <= 'z')
			cl++;

	// deb(cl);

	if (cl >= ip.size()-cl) {
		for (char &c: ip) {
			if (c >= 'A' && c <= 'Z')
				c = c - 'A' + 'a';
		}

	} else {
		for (char &c: ip) {
			if (c >= 'a' && c <= 'z')
				c = c - 'a' + 'A';
		}
	}

	cout << ip;

	return 0;
}