#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define M 1000000007

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a+n, greater<int>());
		ll p = 0;

		for (int i = 0; i < n; i++)
			p = (p + max(0LL, a[i]-i)) % M;

		cout << p << endl;
	}

	return 0;
}