#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef map<int, int> mii;

bool isPossible(mii mp, int n) {

	for (auto x: mp) {
		if (x.second >= n) {
			mp[x.first] -= n;

			int c = 0;
			for (auto y: mp) {
				if (y.second > 0)
					c++;

				if (c == n) {
					mp[x.first] += n;
					return true;					
				}
			}

			mp[x.first] += n;
		}
	}

	return false;
}

int maxPossible(int a[], int n) {

	mii mp;
	for (int i = 0; i < n; i++)
		mp[a[i]]++;

	if (n == 1)
		return 0;

	if (isPossible(mp, n/2))
		return n/2;

	int mid, l = 0, r = n/2;

	while (l < r) {
		mid = (r+l) / 2;

		// deb(l);
		// deb(r);

		if (r-l == 1)
			break;

		if (isPossible(mp, mid))
			l = mid;
		else
			r = mid;
	}

	return mid;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << maxPossible(a, n) << endl;
	}

	return 0;
}