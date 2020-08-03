#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef pair<int, int> pi;

void printSet(multiset<int, greater<int>> s) {
	cout << " -- ";
	for (auto x: s)
		cout << x << " ";
	cout << endl;
}

int tiling(pi a[], int n) {
	sort(a, a+n, greater<pi>());

	multiset<int, greater<int>> inc;
	int lis = 1, set_size;

	for (int i = 0; i < n; i++) {
		auto it = inc.upper_bound(a[i].second);
		if (it != inc.end()) {
			// deb(*it);
			inc.erase(it);
		}
		inc.insert(a[i].second);
		lis = max(lis, set_size = inc.size());

		// printSet(inc);
	}

	return lis;
}

int main() {

	IOS

	int n;

	while (cin >> n && n > 0) {
		pi a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i].first >> a[i].second;

		cout << tiling(a, n) << endl;
	}

	cout << '*' << endl;

	return 0;
}