#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void LIS(int a[], int n, int dp[]) {
	// LDS on reverse

	set<int, greater<int>> inc;

	for (int i = 0; i < n; i++) {
		auto it = inc.lower_bound(a[i]);
		dp[n-1-i] = distance(inc.begin(), it) + 1;

		if (it != inc.end())
			inc.erase(it);

		inc.insert(a[i]);
	}

	// for (int i = 0; i < n; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;
}

void LDS(int a[], int n, int dp[]) {
	// LIS of reverse
	set<int> inc;

	for (int i = 0; i < n; i++) {
		auto it = inc.lower_bound(a[i]);
		dp[n-1-i] = distance(inc.begin(), it) + 1;

		if (it != inc.end())
			inc.erase(it);

		inc.insert(a[i]);
	}

	// for (int i = 0; i < n; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;
}

int trainSort(int a[], int n) {
	int dp_lis[n], dp_lds[n];
	reverse(a, a+n);

	LIS(a, n, dp_lis);
	LDS(a, n, dp_lds);

	int max_len = 0;
	for (int i = 0; i < n; i++)
		max_len = max(max_len, dp_lis[i] + dp_lds[i] - 1);

	return max_len;
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

		cout << trainSort(a, n) << endl;
	}

	return 0;
}