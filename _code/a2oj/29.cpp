#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	string s;
	int x = 0;

	while (t--) {
		cin >> s;

		if (s.find('+') != string::npos)
			x++;
		else
			x--;
	}

	cout << x;

	return 0;
}