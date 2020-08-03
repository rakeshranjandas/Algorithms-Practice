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

	int m;
	cin >> m;

	int b[m];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int mx_ratio = 0, c = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ratio = b[j] / a[i];

			if (ratio * a[i] == b[j]) {
				if (ratio > mx_ratio) {
					mx_ratio = ratio;
					c = 1;
					
				} else if (ratio == mx_ratio)
					c++;
			}
		}
	}

	cout << c;

	return 0;
}