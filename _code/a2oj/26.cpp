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

	bool yes = false;

	for (char x: s) {
		if (x == 'H' || x == 'Q' || x == '9') {
			yes = true;
			break;
		}
	}

	cout << (yes ? "YES" : "NO");

	return 0;
}