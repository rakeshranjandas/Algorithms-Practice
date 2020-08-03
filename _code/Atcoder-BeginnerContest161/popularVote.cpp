#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	IOS

	int n, m;
	cin >> n >> m;

	int a[n], sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	double at_least = (double) sum / (4*m);
	// sort(a, a+n, greater<int>());

	for (int i = 0; i < n; i++) {
		if (double(a[i]) >= at_least)
			m--;

		if (m == 0)
			break;
	}

	cout << (m == 0 ? "Yes" : "No") << endl;

	return 0;
}