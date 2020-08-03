#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	ll n, k;
	cin >> n >> k;

	ll mid = (n+1)/2;

	if (k <= mid) {
		// Then this is an odd
		// What is the kth odd
		cout << (2*(k-1)) + 1;

	} else {
		// This is even
		// What is k-mid'th even
		cout << 2*(k-mid);
	}

	return 0;
}