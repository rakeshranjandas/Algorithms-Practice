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

	int h, m, ph = -1, pm = -1, c = 1, maxc = 1;

	for (int i = 0; i < n; i++) {
		cin >> h >> m;

		if (h == ph && m == pm) {
			c++;
			maxc = max(maxc, c);

		} else {
			c = 1;
			ph = h, pm = m;
		}
	}

	cout << maxc;

	return 0;
}