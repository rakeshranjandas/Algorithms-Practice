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

	while (t--) {
		string s;
		cin >> s;

		if (s.size() <= 10)
			cout << s << endl;

		else {
			cout << (s[0] + to_string(s.size()-2) + s[s.size()-1]) << endl;
		}
	}

	return 0;
}