#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int flr(int x, int y) {
	return x/y;
}

int cel(int x, int y) {
	return (x+y-1) / y;
}

int main() {

	IOS

	int l, r, d;
	cin >> l >> r >> d;

	// deb(flr(r, d));
	// deb(cel(l, d));
	
	cout << (flr(r, d) - cel(l, d) + 1);

	return 0;
}