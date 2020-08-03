#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool sortScore(pair<int, int> &a, pair<int, int> &b) {
	return a.first == b.first ? a.second < b.second : a.first > b.first;
}

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	pair<int, int> a[n];
	map<int, map<int, int>> mp;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		mp[a[i].first][a[i].second]++;
	}

	sort(a, a+n, sortScore);
	auto x = a[k-1];

	cout << mp[x.first][x.second];

	return 0;
}