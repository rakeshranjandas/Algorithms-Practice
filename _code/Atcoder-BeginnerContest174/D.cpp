#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;

	string s;
	cin >> s;

	int cw = 0;
	for (char x: s)
		if (x == 'W')
			cw++;

	int cmw = 0;
	for (int i = n-cw; i < n; i++)
		if (s[i] == 'W')
			cmw++;

	// deb(n-cw-1);
	// deb(cw);
	// deb(cmw);

	cout << cw - cmw;

	return 0;
}