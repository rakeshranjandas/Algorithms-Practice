#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	IOS

	ll n, k;
	cin >> n >> k;

	ll m = n%k;
	cout << min(m, k-m) << endl;

	return 0;
}