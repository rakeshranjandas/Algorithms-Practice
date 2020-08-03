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

	unordered_set<int> present;

	int dp[n+1];
	dp[n] = 0;

	for (int i = n-1; i >= 0; i--) {
		dp[i] = dp[i+1];

		if (present.find(a[i]) == present.end()) {
			present.insert(a[i]);
			dp[i]++;
		}
	}

	int l;
	for (int q = 0; q < m; q++) {
		cin >> l;
		cout << dp[l-1] << endl;
	}

	return 0;
}