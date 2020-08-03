#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	ll a, b, n;
	cin >> a >> b >> n;

	ll x = min(b-1, n);
	ll ans = (a * x) / b;

	cout << ans << endl;

	return 0;
}