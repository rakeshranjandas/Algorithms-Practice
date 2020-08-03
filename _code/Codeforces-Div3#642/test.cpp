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
		int n, m, res;
		cin >> n >> m;

		if (n == 1)
			res = 0;

		else if (n == 2)
			res = m;

		else
			res = 2*m;

		cout << res << endl;

	}

	return 0;
}