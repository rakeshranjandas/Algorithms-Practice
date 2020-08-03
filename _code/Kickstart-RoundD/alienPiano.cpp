#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int rec(int a[], int start, int n, int dp[]) {
	if (start == n)
		return 0;

	if (dp[start] != -1)
		return dp[start];

	set<int> st;
	int min_break = INT_MAX;

	for (int i = start; i < n; i++) {
		st.insert(a[i]);
		if (st.size() == 5)
			break;

		if (i == n-1) 
			min_break = 0;
		else
			min_break = min(min_break, 1+rec(a, i+1, n, dp));
	}

	return dp[start] = min_break;
}

void solve() {
	int n;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int dp[n+1];
	memset(dp, -1, sizeof(dp));

	int c = rec(a, 0, n, dp);

	cout << c;
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