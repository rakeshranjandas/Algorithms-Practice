#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
int n, t, sum;
int a[20];

int dp[1<<20];

int solve(int mask, int sum_till_now) {

	if (dp[mask] != -1) {
		// deb(dp[mask]);
		return dp[mask];
	}

	if (sum_till_now > sum/4)
		return 0;

	if (sum_till_now == sum/4) {
		if (mask == (1<<n)-1)
			return 1;

		sum_till_now = 0;
	}

	for (int i = 0; i < n; i++)	{
		if (mask & 1<<i)
			continue;

		if (solve(mask | 1<<i, sum_till_now+a[i]))
			return 1;
	}

	dp[mask] = 0;
	return 0;
}

int main() {

	IOS

	cin >> t;

	while (t--) {

		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sum = accumulate(a, a+n, 0);

		if (sum%4 == 0) {
			
			memset(dp, -1, sizeof(dp));
			int can = solve(0, 0);

			cout << (can ? "yes" : "no") << endl;

		} else
			cout << "no" << endl;
	}

	return 0;
}