#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int a, b, c, k;
	cin >> a >> b >> c >> k;

	int sum;
	sum = min(k, a);
	k -= min(k, a);

	if (k > 0) {
		k -= min(k, b);

		if (k > 0) {
			sum -= min(k, c);
			k -= min(k, c);
		}
	}

	cout << sum << endl;

	return 0;
}