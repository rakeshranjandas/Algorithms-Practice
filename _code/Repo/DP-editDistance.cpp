#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define N 100

#define deb(x)	cout << #x << " " << x << endl;

void printDP(int dp[][N], int l1, int l2) {

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
			cout << "[" << i << "][" << j << "]" << dp[i][j] << " ";
		cout << endl;
	}
}


int editDistance(string s1, string s2, int ind1, int ind2, int dp[][N]) {

	if (ind1 >= s1.size()) {
		return s2.size()-ind2;
	}

	if (ind2 >= s2.size()) {
		return s1.size()-ind1;
	}

	if (dp[ind1][ind2] != -1)
		return dp[ind1][ind2];

	int replace_cost = (s1[ind1] == s2[ind2] ? 0:1) + editDistance(s1, s2, ind1+1, ind2+1, dp);
	int insert_cost = 1 + editDistance(s1, s2, ind1, ind2+1, dp);
	int remove_cost = 1 + editDistance(s1, s2, ind1+1, ind2, dp);

	int min_cost = min(replace_cost, min(insert_cost, remove_cost));

	dp[ind1][ind2] = min_cost;

	return min_cost;
}

void init2dDP(int dp[][N], int n1, int n2) {
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			dp[i][j] = -1;
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
		int l1, l2;
		cin >> l1 >> l2;

		string s1, s2;
		cin >> s1 >> s2;

		int dp[l1][N];
		init2dDP(dp, l1, l2);

		cout << editDistance(s1, s2, 0, 0, dp) << endl;
	}

	return 0;
}