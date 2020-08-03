#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool sortPair(pair<int, int> &p1, pair<int, int> &p2) {
	return (p1.first == p2.first) ? (p1.second >= p2.second) : (p1.first < p2.first);
}

int main() {

	IOS

	int s, n;
	cin >> s >> n;

	pair<int, int> a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a, a+n);
	bool can = true;

	for (int i = 0; i < n; i++) {
		// deb(a[i].first); deb(a[i].second); 

		if (s <= a[i].first) {
			can = false;
			break;
		}

		s += a[i].second;
	}

	cout << (can ? "YES" : "NO");


	return 0;
}