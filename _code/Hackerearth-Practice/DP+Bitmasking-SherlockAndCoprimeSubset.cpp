#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 51

int max_len = 0;
map<int, int> prime_ind;
int dp[N][(1 << 15) + 1];

int getMask(int num) {

	int mask = 0;

	for (auto x: prime_ind) {
		if (num % x.first == 0)
			mask = mask | 1 << x.second;
	}

	return mask;
}

int solve(int a[], int n, int mask, int cur) {

	// deb(cur);

	if (cur == n)
		return 0;

	if (dp[cur][mask] != -1)
		return dp[cur][mask];

	int exc = solve(a, n, mask, cur+1);
	int inc = 0;

	int cur_mask = getMask(a[cur]);

	if (mask == 0 || !(mask & cur_mask)) {
		inc = 1 + solve(a, n, mask | cur_mask, cur+1);
	}

	int len = max(inc, exc);
	max_len = max(max_len, len);

	dp[cur][mask] = len;


	// deb(mask); deb(cur_mask); deb(a[cur]);
	// deb((mask & cur_mask));
	// cout << cur << ": "  << cur_mask << " . "
	// 	<< a[cur] << "(" << mask << ") >> " 
	// 	<< inc << " " << exc << " - " << len << endl << endl;

	return len;
}

void init() {
	bool composite[N] = {0};
	int pi = 1;

	for (int i = 2; i < N; i++) {
		if (composite[i])
			continue;

		prime_ind[i] = pi++;

		for (int k = 2; i*k < N; k++)
			composite[i*k] = true;
	}

	// for (auto x: prime_ind)
	// 	cout << x.first << "-" << x.second << endl;
}

int main() {

	IOS

	init();

	// deb(getMask(47));
	// return 0;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		max_len = 0;
		memset(dp, -1, sizeof(dp));
		solve(a, n, 0, 0);

		cout << max_len << endl;
	}

	return 0;
}