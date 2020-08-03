#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int rs = 0;
	for (int i = 0; i < k; i++)
		rs += a[i];
	int res = 0, ms = rs;

	for (int i = 1; i+k-1 < n; i++) {
		rs -= a[i-1];
		rs += a[i+k-1];

		// deb(i-1);
		// deb(i+k-1);

		if (rs < ms) {
			res = i;
			ms = rs;
		}
	}

	cout << res+1;

	return 0;
}