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
	int i = 0;

	bool ins_loop;

	while (i < s.size()) {
		ins_loop = false;

		while (i+3 <= s.size() && s.substr(i, 3) == "WUB") {

			i += 3;
			ins_loop = true;
		}

		if (i == s.size())
			break;

		if (ins_loop && res != "") {
			res += " ";
			continue;
		}

		res += s[i];
		i++;
	}

	cout << res;

	return 0;
}