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

	map<ll, ll> mp;
	ll ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		mp[ip]++;
	}

	if (mp.size() == 1) {
		cout << to_string(0) << " " << to_string(((mp.begin())->second *((mp.begin())->second-1))/2);
	} else {
		cout << (mp.rbegin())->first - (mp.begin())->first 
			<< " " << (mp.begin())->second * (mp.rbegin())->second;

	}

	return 0;
}