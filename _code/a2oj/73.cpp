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

	auto it = s.find('0');

	if (it != string::npos) {
		s.erase(s.begin() + it);

	} else {
		s.erase(s.begin());
	}

	cout << s;

	return 0;
}