#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string s1, s2;
	cin >> s1 >> s2;
	
	int cmp = 0;

	for (int i = 0; i < s1.size(); i++) {
		if (tolower(s1[i]) < tolower(s2[i])) {
			cmp = -1;
			break;

		} else if (tolower(s1[i]) > tolower(s2[i])) {
			cmp = 1;
			break;
		}
	}

	cout << cmp;

	return 0;
}