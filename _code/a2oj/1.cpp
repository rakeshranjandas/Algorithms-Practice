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

	int x[n], y[n], z[n];

	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> z[i];

	int accx = accumulate(x, x+n, 0);
	int accy = accumulate(y, y+n, 0);
	int accz = accumulate(z, z+n, 0);

	cout << (accx == 0 && accy == 0 && accz == 0 ? "YES": "NO");

	return 0;
}