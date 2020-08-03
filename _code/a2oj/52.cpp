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

	int c = 0;
	char last = 'x';
	bool dangerous = false;

	for (char x: s) {
		if (x == last)
			c++;

		else {
			last = x;
			c = 1;
		}

		if (c >= 7) {
			dangerous = true;
			break;
		}
	}

	cout << (dangerous ? "YES" : "NO");

	return 0;
}