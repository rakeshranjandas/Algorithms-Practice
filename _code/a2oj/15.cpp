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

	double c = 0;
	double ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		c += ip / 100;
	}

	cout << fixed << setprecision(12) << (c/n) * 100;

	return 0;
}