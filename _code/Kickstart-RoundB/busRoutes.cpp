#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		int n;
		cin >> n;

		ll d;
		cin >> d;

		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		a[n-1] = d-d%a[n-1];
		for (int i = n-2; i >= 0; i--)
			a[i] = a[i+1]-a[i+1]%a[i];

		cout << "Case #" << t_i << ": " << a[0] << endl;
	}

	return 0;
}