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

	reverse(s.begin(), s.end());

	cout << (s == t ? "YES" : "NO");

	return 0;
}