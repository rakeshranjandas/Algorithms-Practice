#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 10001
// #define N 11

int main() {

	IOS

	int a, b, c;
	cin >> a >> b >> c;

	bool found = false;

	for (int i = 1; i < N && !found; i++) {
		for (int j = 1; j < N && !found; j++) {
			// deb(i);deb(j);

			if (i*j == a && b%j == 0) {
				int k = b/j;
				if (i*k == c) {
					found = true;
					cout << 4*(i+j+k);
				}
			}
		}
	}

	return 0;
}