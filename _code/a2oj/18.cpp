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

	int p;
	cin >> p;

	int minm = p, maxm = p, c = 0;

	for (int i = 1; i < n; i++) {
		cin >> p;

		if (p > maxm) {
			c++;
			maxm = p;

		} else if (p < minm) {
			c++;
			minm = p;
		}
	}

	cout << c;

	return 0;
}