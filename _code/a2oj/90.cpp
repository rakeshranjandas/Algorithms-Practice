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

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll acc1[n+1], acc2[n+1];

	acc1[0] = 0;
	for (int i = 0; i < n; i++)
		acc1[i+1] = acc1[i] + a[i];

	sort(a, a+n);
	
	acc2[0] = 0;
	for (int i = 0; i < n; i++)
		acc2[i+1] = acc2[i] + a[i];

	int m;
	cin >> m;

	int type, l, r;

	for (int i = 0; i < m; i++) {
		cin >> type >> l >> r;

		if (type == 1) {
			cout << acc1[r]- acc1[l-1] << endl;

		} else {
			cout << acc2[r]- acc2[l-1] << endl;
		}
	}


	return 0;
}