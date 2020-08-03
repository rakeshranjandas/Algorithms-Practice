#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void solve() {
	int n;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int c = 0, max_till_now = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (a[i] > max_till_now) {
			max_till_now = a[i];

			if (i == n-1 || a[i] > a[i+1])
				c++;
		}
	}

	cout << c ;
	
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		cout << "Case #" << t_i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}