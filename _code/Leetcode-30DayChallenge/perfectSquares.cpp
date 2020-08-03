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
	for (int i = 0; i <= n; i++)
		a[i] = i;

	for (int i = 2; i*i <= n; i++) {
		int num = i*i;

		for (int j = 0; j+num <= n; j++)
			a[j+num] = min(a[j]+1, a[j+num]);
	}

	// for (int i = 0; i <= n; i++)
	// 	cout << "(" << i << ")" << a[i] << ", ";
	// cout << endl;

	return 0;
}