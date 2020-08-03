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

	bool dash = false;
	string res = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			if (dash) {
				dash = false;
				res += '1';

			} else {
				res += '0';
			}
		} else {
			if (dash) {
				dash = false;
				res += '2';

			} else {
				dash = true;
			}
		}
	}

	cout << res;

	return 0;
}