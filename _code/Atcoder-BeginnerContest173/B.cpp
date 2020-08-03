#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;

	map<string, int> mp;
	string x;

	for (int i = 0; i < n; i++) {
		cin >> x;
		mp[x]++;
	}

	cout << "AC x " << mp["AC"] << endl;
	cout << "WA x " << mp["WA"] << endl;
	cout << "TLE x " << mp["TLE"] << endl;
	cout << "RE x " << mp["RE"] << endl;

	return 0;
}