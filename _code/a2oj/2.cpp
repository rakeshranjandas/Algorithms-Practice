#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int x, y, ip;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> ip;

			if (ip == 1) {
				x = i, y = j;
			}
		}
	}

	cout << (abs(x-2) + abs(y-2));

	return 0;
}