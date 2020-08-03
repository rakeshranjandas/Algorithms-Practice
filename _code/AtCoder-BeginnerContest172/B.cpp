#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string s, t;
	cin >> s >> t;

	int c = 0;

	for (int i = 0; i < s.size(); i++)
		if (s[i] != t[i])
			c++;

	cout << c;

	return 0;
}