#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 1001

int main() {

	IOS

	int n;
	cin >> n;

	int a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	int c = 0;
	for (int i = 0; i < n; i++) {
		bool can_open = false;

		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;

			if (a[i] == b[j]) {
				can_open = true;
				break;
			}
		}

		if (!can_open)
			c++;
	}

	cout << c;

	return 0;
}