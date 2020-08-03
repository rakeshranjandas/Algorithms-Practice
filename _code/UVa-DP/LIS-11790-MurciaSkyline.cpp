#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void LIS(int h[], int w[], int n, int dp[]) {

	dp[0] = w[0];

	for (int i = 1; i < n; i++) {
		dp[i] = w[i];
		for (int j = 0; j < i; j++) {
			if (h[j] < h[i]) {
				dp[i] = max(dp[i], w[i] + dp[j]);
			}
		}

		// for (int k = 0; k < n; k++)
		// 	cout << dp[k] << " ";
		// cout << endl;
	}
}

void SOLVE(int h[], int w[], int n) {
	int dp_inc[n] = {0}, dp_dec[n] = {0};

	LIS(h, w, n, dp_inc);

	reverse(h, h+n);
	reverse(w, w+n);

	LIS(h, w, n, dp_dec);

	int lis_w = *max_element(dp_inc, dp_inc+n);
	int lds_w = *max_element(dp_dec, dp_dec+n);

	if (lis_w >= lds_w)
		cout << "Increasing (" << lis_w << "). Decreasing (" << lds_w << ").";

	else
		cout << "Decreasing (" << lds_w << "). Increasing (" << lis_w << ").";
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		int n;
		cin >> n;

		int h[n], w[n];

		for (int i = 0; i < n; i++)
			cin >> h[i];

		for (int i = 0; i < n; i++)
			cin >> w[i];

		cout << "Case " << t_i << ". ";
		SOLVE(h, w, n);
		cout << endl;
	}

	return 0;
}