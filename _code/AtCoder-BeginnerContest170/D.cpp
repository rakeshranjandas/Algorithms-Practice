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

	map<int, int> mp;
	int ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		mp[ip]++;
	}

	vector<pair<int, int>> v;
	for (auto x: mp)
		v.push_back({x.first, x.second});

	int c = 0;

	for (auto it = v.begin(); it != v.end(); it++) {

		if (it->second > 1)
			continue;

		auto jit = v.begin();
		for (; jit != it; jit++) {
			if (it->first % jit->first == 0)
				break;
		}

		if (jit == it)
			c++;
	}

	cout << c;

	return 0;
}