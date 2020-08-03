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

	int a[n+1], ip;

	for (int i = 1; i <= n; i++) {
		cin >> ip;

		a[ip] = i;
	}

	int q;
	cin >> q;
	
	ll va = 0, pe = 0;

	while (q--) {
		cin >> ip;
		
		va += a[ip];
		pe += n-a[ip]+1;

	}

	cout << va << " " << pe;
	return 0;
}