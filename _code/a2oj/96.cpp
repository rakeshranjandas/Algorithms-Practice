#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define M 1000000007

int main() {

	IOS

	ll x, y;
	cin >> x >> y;

	ll f[6];
	f[0] = (x + M) % M;
	f[1] = (y + M) % M;

	for (int i = 2; i < 6; i++)
		f[i] = (f[i-1] - f[i-2] + M) % M;

	// for (int i = 0; i < 6; i++)
	// 	cout << f[i] << " ";
	// cout << endl;

	int n;
	cin >> n;
	--n;

	cout << f[n%6];

	return 0;
}