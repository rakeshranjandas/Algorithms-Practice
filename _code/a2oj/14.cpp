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

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int maxpos, maxm = INT_MIN, minpos, minm = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (a[i] > maxm) {
			maxpos = i;
			maxm = a[i];
		}

		if (a[i] <= minm) {
			minpos = i;
			minm = a[i];
		}
	}

	int dist = maxpos + (n-1 - minpos);
	
	if (maxpos > minpos)
		dist--;

	cout << dist;

	return 0;
}