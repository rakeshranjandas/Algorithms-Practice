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

	int a[n+1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a+1, a+n+1);

	ll moves = 0;
	for (int i = 1; i <= n; i++) {
		moves += abs(i - a[i]);
	}

	cout << moves;

	return 0;
}