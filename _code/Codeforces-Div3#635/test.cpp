#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int findx(int n) {

	int twos = 4;

	while (n > twos) {
		if (n % (twos - 1) == 0)
			break;

		twos *= 2;

		// deb(twos);
	}

	return n/(twos - 1);
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << findx(n) << endl;
	}

	return 0;
}