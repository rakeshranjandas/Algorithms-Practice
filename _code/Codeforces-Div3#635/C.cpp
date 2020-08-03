#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int sign(int n) {
	return n > 0 ? 1: 0;
}

ll maxSum(int a[], int n, int cur) {

	if (cur == n)
		return 0;

	int i = cur, chosen = a[cur];

	for (; i < n; i++) {

		if(sign(a[cur]) != sign(a[i])) {
			break;
		}

		chosen = max(chosen, a[i]);
	}

	return chosen + maxSum(a, n, i);
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << maxSum(a, n, 0) << endl;
	}

	return 0;
}