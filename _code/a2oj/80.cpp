#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	  freopen("input.txt", "rt", stdin);
	  freopen("output.txt", "wt", stdout);

	int n, m;
	cin >> n >> m;

	if(n > m) {

		while (n > 0 || m > 0) {
			if (n > 0) {
				cout << 'B';
				n--;
			}

			if (m > 0) {
				cout << 'G';
				m--;
			}
		}

	} else {

		while (n > 0 || m > 0) {
			if (m > 0) {
				cout << 'G';
				m--;
			}

			if (n > 0) {
				cout << 'B';
				n--;
			}
		}
	}

	return 0;
}