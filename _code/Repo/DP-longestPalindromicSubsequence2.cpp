#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 1001

int LCS(string &s1, string &s2, int ind1, int ind2, int dp[][N]) {

	// deb(s1);
	// cout << "ind1 " << ind1 << ", ind2 " << ind2 << endl;

	if (ind1 >= s1.size() || ind2 >= s2.size())
		return 0;

	if (dp[ind1][ind2] != -1)
		return dp[ind1][ind2];

	int val = 0, last, new_one;

	for (int i = ind2; i < s2.size(); i++){

		if (s1[ind1] != s2[i])
			continue;

		last = LCS(s1, s2, ind1+1, i+1, dp);
		new_one = 1 + last;

		// cout << endl;
		// deb(s1[ind1]);
		// deb(s2[i]);
		// deb(new_one);

		val = max(val, new_one);
	}

	int without = LCS(s1, s2, ind1+1, ind2, dp);
	val = max(val, without);


	dp[ind1][ind2] = val;
	// cout << "s1 " << s1.substr(ind1) << ", s2 " << s2.substr(ind2) << " val " << val << endl;

	return val;
}

void initDP(int dp[][N], int n1, int n2) {
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

		string s1;
		cin >> s1;

		string s2 = s1;
		reverse(s2.begin(), s2.end());

		int n = s1.size();

		int dp[n][N];
		initDP(dp, n, n);

		cout << LCS(s1, s2, 0, 0, dp) << endl;
	}

	return 0;
}