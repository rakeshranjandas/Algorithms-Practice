#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

void printMap(map<int, long long int> mm) {
	for (auto x: mm)
		cout << "[" << x.first << "]" << x.second << ", ";
	cout << endl;
}

long long int maxSumIncSubseq(int a[], int n) {
	long long int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = a[i];

	long long int max_sum = dp[0];

	for (int j = 1; j < n; j++) {
		for (int i = 0; i < j; i++)
			if (a[i] < a[j])
				dp[j] = max(dp[j], a[j]+dp[i]);

		max_sum = max(max_sum, dp[j]);
	}

	return max_sum;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << maxSumIncSubseq(a, n) << endl;
	}

	return 0;
}