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

		int c_o = 0, c_e = 0, d_o = 0;

		for (int i = 0; i < n; i++) {
			
			if (i > 0) {
				if (abs(a[i] - a[i-1]) == 1)
					d_o++;
			}

			if (a[i]%2 == 0)
				c_e++;
			else
				c_o++;
		}

		// deb(c_e);
		// deb(c_o);
		// deb(d_o);
		
		cout << ((c_e%2 == 0 && c_o%2 == 0) || d_o > 0 ? "YES" : "NO") << endl;
	}

	return 0;
}