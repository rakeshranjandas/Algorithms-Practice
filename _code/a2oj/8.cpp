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

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] = s[0] - 'a' + 'A' ;

	cout << s;

	return 0;
}