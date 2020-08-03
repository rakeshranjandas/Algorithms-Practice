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
		int n, k;
		cin >> n >> k;

		ll a[n], b[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n; i++)
			cin >> b[i];

		sort(a, a+n);
		sort(b, b+n, greater<int>());

		for (int i = 0; i < k; i++) {
			if (a[i] >= b[i])
				break;

			int temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}

		cout << accumulate(a, a+n, (ll)0) << endl;

	}

	return 0;
}