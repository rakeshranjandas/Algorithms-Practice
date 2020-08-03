#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl “\n”
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {

		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int peaks = 0;
		for (int i = 1; i < n-1; i++)
			if (a[i-1] < a[i] && a[i] > a[i+1])
				peaks++;

		cout << "Case #" << t_i << ": " << peaks << endl;
	}

	return 0;
}