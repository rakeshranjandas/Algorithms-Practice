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

	int i = 0, n = s.size();
	bool ok = true;

	while (i < n) {
		if (i+2 < n && s[i] == '1' && s[i+1] == '4' && s[i+2] == '4') {
			i += 3;
			continue;
		}

		if (i+1 < n && s[i] == '1' && s[i+1] == '4') {
			i += 2;
			continue;
		}

		if (s[i] == '1') {
			i++;
			continue;
		}

		ok = false;
		break;
	}

	cout << (ok ? "YES" : "NO");

	return 0;
}