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

	int c[4] = {0};

	for (int i = 0; i < s.size(); i+=2)
		c[s[i] - '0']++;

	string res = "";

	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < c[i]; j++) {
			res += (i + '0');
			res += "+";
		}
	}

	cout << res.substr(0, res.size()-1);

	return 0;
}