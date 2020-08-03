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

	string team;
	map<string, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> team;
		mp[team]++;
	}

	int max_g = 0;
	string winning_team;

	for (auto x: mp) {
		if (x.second > max_g) {
			max_g = x.second;
			winning_team = x.first;
		}
	}

	cout << winning_team;

	return 0;
}