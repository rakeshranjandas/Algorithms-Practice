#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;
		int b = n/2;
		if (n % 2 == 0)
			b--;

		cout << b << endl;
	}

	return 0;
}