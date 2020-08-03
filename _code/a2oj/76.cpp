#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, m;
	cin >> n >> m;

	int c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	int w[m];
	for (int i = 0; i < m; i++)
		cin >> w[i];

	int min_c = *min_element(c, c+n);
	int max_c = *max_element(c, c+n);

	int min_w = *min_element(w, w+m);

	// deb(min_c);
	// deb(max_c);
	// deb(min_w);

	int res = -1;

	for (int i = max_c; i < min_w; i++) {
		if (2*min_c <= i) {
			res = i;
			break;
		}
	}

	cout << res;

	return 0;
}