#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 13
#define NEG_INF -100

int a[4][N];
int n;
int dp[4][281][1<<13];

int findMaxSolved(int last, int rem, int mask) {
	if (rem < 0)
		return NEG_INF;

	if (dp[last][rem][mask] != -1)
		return dp[last][rem][mask];

	if (mask == (1<<n)-1)
		return 0;

	int max_solved = 0;

	for (int person = 0; person < 3; person++) {
		if (person == last)
			continue;

		for (int ques = 0; ques < n; ques++) {
			if (mask & 1<<ques)
				continue;

			int new_rem = rem - a[person][ques];
			int new_mask = mask | 1<<ques;

			max_solved = max(max_solved, 1 + findMaxSolved(person, new_rem, new_mask));
		}
	}

	return dp[last][rem][mask] = max_solved;
}

void solve() {
	cin >> n;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	memset(dp, -1, sizeof(dp));

	cout << findMaxSolved(3, 280, 0) << endl;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}