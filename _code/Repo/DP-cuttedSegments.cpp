#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 3

long long int cuttedSegmentUtil(vector<int> &v, int k, int now_ind, int dp[][N]) {

	if (k < 0)
		return -1;

	if (now_ind >= v.size())
		return -1;

	if (dp[k][now_ind] > 0)
		return dp[k][now_ind];

	if (k == 0) {
		dp[k][now_ind] = 0;
		return 0;
	}


	int ways, max_ways = -1;
	for (auto it = now_ind; it < v.size(); it++) {
		ways = cuttedSegmentUtil(v, k-v[it], it, dp);
		if (ways != -1)
			max_ways = max(max_ways, ways);
	}

	if (max_ways != -1)
		dp[k][now_ind] = max_ways + 1;

	return dp[k][now_ind];
}

int cuttedSegment(vector<int> &v, int k) {

	int dp[k+1][N];
	for (int i = 0; i < k+1; i++)
		for (int j = 0; j < N; j++)
			dp[i][j] = -1;

	return cuttedSegmentUtil(v, k, 0, dp);
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
		int k;
		cin >> k;

		set<int> s;
		int ip;

		for (int i = 0; i < N; i++) {
			cin >> ip;
			s.insert(ip);
		}

		vector<int> v(s.begin(), s.end());

		cout << cuttedSegment(v, k) << endl;
	}

	return 0;
}