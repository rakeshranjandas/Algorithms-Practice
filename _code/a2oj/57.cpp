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

	int a[m];
	for (int i = 0; i < m; i++)
		cin >> a[i];

	sort(a, a+m);
	int min_diff = INT_MAX;

	for (int i = 0; i+n-1 < m; i++)
		min_diff = min(min_diff, a[i+n-1] - a[i]);

	cout << min_diff;

	return 0;
}