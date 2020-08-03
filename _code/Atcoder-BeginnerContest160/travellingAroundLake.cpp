#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	FILE_WR
	IOS

	int k, n;
	cin >> k >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int diff[n];
	for (int i = 0; i < n-1; i++)
		diff[i] = a[i+1] - a[i];

	diff[n-1] = k - a[n-1] + a[0];

	sort(diff, diff+n);
	int dist = 0;
	for (int i = 0; i < n-1; i++)
		dist += diff[i];

	cout << dist << endl;

	return 0;
}