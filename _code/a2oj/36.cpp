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

	int min_diff = abs(a[n-1] - a[0]), ai = n-1, aj = 0, diff;

	for (int i = 1; i < n; i++) {
		diff = abs(a[i] - a[i-1]);

		if (diff < min_diff) {
			min_diff = diff;
			ai = i-1, aj = i;
		}
	}

	cout << ai+1 << " " << aj+1;

	return 0;
}