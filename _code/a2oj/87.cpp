#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int pieces = 0;
	for (int i = 0; i*a <= n; i++) {
		for (int j = 0; i*a + j*b <= n; j++) {
			int left = n-(i*a + j*b);
			if (left >= 0 && left % c == 0) {
				pieces = max(pieces, i+j+left/c);
			}
		}
	}

	cout << pieces;

	return 0;
}