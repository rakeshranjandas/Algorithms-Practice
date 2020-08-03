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

	string p = "hello";
	int pi = 0;
	bool can = false;

	for (char c: s) {
		if (c == p[pi]) {
			pi++;
			if (pi == p.size()) {
				can = true;
				break;
			}
		}
	}

	cout << (can ? "YES" : "NO");

	return 0;
}