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

	int c0 = 0, c5 = 0, ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;

		if (ip == 0)
			c0++;
		else
			c5++;
	}
	
	if (c0 == 0)
		cout << "-1";

	else {
		c5 = (c5/9) * 9;
		string s = (c5 == 0 ? "0" : (string (c5, '5') + string(c0, '0')));

		cout << s;
	}

	return 0;
}