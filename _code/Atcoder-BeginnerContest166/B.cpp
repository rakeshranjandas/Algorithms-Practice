#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	bool a[n+1] = {0};
	int d, ip;

	for (int i = 0; i < k; i++) {
		cin >> d;
		for (int j = 0; j < d; j++) {
			cin >> ip;
			a[ip] = true;
		}
	}

	int c = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 0)
			c++;

	cout << c << endl;

	return 0;
}