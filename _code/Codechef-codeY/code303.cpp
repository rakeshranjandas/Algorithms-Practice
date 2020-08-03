#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 101
#define M 101

typedef long long int ll;

int ways(int a[], int n, int cur, int left, int dp[][M]) {

	if (left == 0)
		return 1;

	if (left < 0)
		return 0;

	if (cur >= n)
		return 0;

	// if (dp[cur][left] != -1)
	// 	return dp[cur][left];

	int total_ways = 0;

	for (int i = cur; i < n; i++) {
		total_ways += ways(a, n, i+1, left-a[i], dp);
	}

	// dp[cur][left] = total_ways;

	return total_ways;
}

void init2dDP(int dp[][M], int n1, int n2) {
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			dp[i][j] = -1;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int dp[N][M];
		init2dDP(dp, n, m);

		cout << ways(a, n, 0, m, dp) << endl;
	}

	return 0;
}