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

	int pref[n+1];
	pref[0] = 0;

	for (int i = 0; i < n; i++)
		pref[i+1] = pref[i] + a[i];

	int max1 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j <= n; j++) {

			int c1 = pref[j] - pref[i];
			int c0 = j - i - c1;

			// cout << i << " " << j << " " << c1 << " " << c0 << endl;

			int c1afterflip = c0 + pref[i] + pref[n] - pref[j];

			max1 = max(max1, c1afterflip);
		}
	}

	cout << max1;

	return 0;
}