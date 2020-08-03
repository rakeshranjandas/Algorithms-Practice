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

	ll prod = 1, ip;
	ll limit = 1000000000000000000;

	for (int i = 0; i < n; i++) {
		cin >> ip;

		if (prod == 0 || ip == 0) {
			prod = 0;

		} else if (prod == -1) {

		} else {
			if (ip > ((limit/prod) + 1)) {
				prod = -1;
			} else {
				prod *= ip;

				if (prod > limit)
					prod = -1;
			}
		}
	}

	cout << prod << endl;

	return 0;
}