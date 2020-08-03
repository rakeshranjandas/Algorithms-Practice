#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string ip;
	cin >> ip;

	int cnt = 0;
	for (char c: ip) {
		if (c == '4' || c == '7')
			cnt++;
	}

	cout << (cnt == 4 || cnt == 7 ? "YES": "NO");

	return 0;
}