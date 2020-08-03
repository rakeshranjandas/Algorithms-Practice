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

	string res = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.')
			res += '0';

		else {
			if (s[i+1] == '.')
				res += '1';
			else
				res += '2';

			i++;
		}
	}

	cout << res << endl;

	return 0;
}