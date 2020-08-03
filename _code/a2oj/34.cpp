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

	int a[n] = {0}, sum = 0, ip;

	for (int i = 0; i < 7; i++) {
		cin >> ip;
		sum += ip;
		a[i] = sum;
	}

	n %= sum;

	if (n == 0)
		n = sum;

	// deb(n);
	// for (int i = 0; i < 7; i++)
	// 	cout << a[i] << " ";
	// cout << endl;

	cout << (n == 0 ? 7 : (distance(a, lower_bound(a, a+7, n)) + 1)) << endl;

	return 0;
}