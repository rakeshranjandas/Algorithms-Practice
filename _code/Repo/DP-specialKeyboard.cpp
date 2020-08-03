#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 76

int countA(int cur, int moves, int buffer, bool is_scp, int *max_a,
	unordered_map<int, unordered_map<int, int>> &dp) {

	if (moves == 0)
		return cur;

	int str_appended_typea = 0, str_appended_scp = 0, str_appended_p = 0;

	int len_by_typea = cur+1;
	str_appended_typea = countA(len_by_typea, moves-1, buffer, false, max_a, dp);

	int len_by_scp = 0;
	if (moves >= 3) {

		len_by_scp = 2*cur;

		if(dp.find(cur) != dp.end() && dp[cur].find(moves) != dp[cur].end())
			str_appended_scp = dp[cur][moves];
		else
			str_appended_scp = countA(len_by_scp, moves-3, cur, true, max_a, dp);		
	}

	int len_by_p = 0;
	if (buffer > 0) {
		len_by_p = cur + buffer;
		str_appended_p = countA(len_by_p, moves-1, buffer, false, max_a, dp);
	}

	*max_a = max(*max_a, max(len_by_p, max(len_by_typea, len_by_scp)));

	return max(str_appended_p, max(str_appended_scp, str_appended_typea));
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

		int max_a = 0;
		unordered_map<int, unordered_map<int, int>> dp;

		countA(1, n-1, 0, false, &max_a, dp);

		cout << max_a << endl;
	}

	return 0;
}