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
	int x;

	for (int i = 0; i < n; i++) {
		cin >> x;
		mp[x]++;
	}

	bool can = true;

	for (auto x: mp) {
		if (x.second > ((n-1)/2 + 1)) {
			can = false;
			break;
		}
	}

	cout << (can ? "YES" : "NO");

	return 0;
}