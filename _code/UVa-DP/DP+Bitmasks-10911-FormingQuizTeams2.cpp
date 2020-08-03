#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

double dp[1<<16];

bool allTeamsFormed(int mask, int n) {

	for (int i = 0; i < 2*n; i++) {
		if (!(mask & 1<<i))
			return false;
	}

	return true;
}

int sq(int n) {
	return n*n;
}

double findDist(int x1, int y1, int x2, int y2) {
	return sqrt(sq(y1-y2) + sq(x1-x2));
}

double solve(int n, int x[], int y[], int mask) {
	if (allTeamsFormed(mask, n))
		return 0;

	if (dp[mask] != -1)
		return dp[mask];

	int first_unset;
	for (int i = 0; i < 2*n; i++) {
		if (!(mask & 1<<i)) {
			first_unset = i;
			break;
		}
	}

	double min_dist = DBL_MAX, team_dist, new_dist;
	int first_mask = 1<<first_unset;

	for (int i = first_unset+1; i < 2*n; i++) {
		if (mask & 1<<i)
			continue;

		team_dist = findDist(x[first_unset], y[first_unset], x[i], y[i]);
		new_dist = team_dist + solve(n, x, y, mask | first_mask | 1<<i);

		min_dist = min(min_dist, new_dist);
	}

	dp[mask] = min_dist;

	return min_dist;
}

int main() {

	IOS

	int n, t_i = 1;

	while (cin >> n && n > 0) {
		int x[2*n], y[2*n];
		string name;

		for (int i = 0; i < 2*n; i++)
			cin >> name >> x[i] >> y[i];

		for (int i = 0; i < 1<<16; i++)
			dp[i] = -1;

		double min_dist = solve(n, x, y, 0);

		cout << "Case " << t_i++ << ": " << fixed << setprecision(2) << min_dist << endl;
	}

	return 0;
}