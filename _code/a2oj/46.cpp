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

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a+n);

	int earn = 0;
	for (int i = 0; i < min(n, m) && a[i] <= 0; i++)
		earn += abs(a[i]);

	cout << earn;

	return 0;
}