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

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a+n);
		int min_diff = abs(a[1] - a[0]);

		for (int i = 2; i < n; i++)
			min_diff = min(min_diff, abs(a[i] - a[i-1]));

		cout << min_diff << endl;
	}

	return 0;
}