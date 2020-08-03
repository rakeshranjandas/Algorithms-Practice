#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
double dp[8][1<<16];

int sq(int n) {
	return n*n;
}

double findDist(int x1, int y1, int x2, int y2) {
	return sqrt(sq(y1-y2) + sq(x1-x2));
}

double solve(int n, int x[], int y[], int cur, int mask, int team[]) {

	// deb(mask);

	if (cur == 2*n)
		return 0;

	if (dp[mask] != -1)
		return dp[mask];

	// 00 
	// 10
	double dist = DBL_MAX;

	for (int i = 0; i < n; i++)	{

		// if 11, continue, no team full
		if ((mask & 3<<(2*i)) == (3<<(2*i)))
			continue;

		// if 00, team not even started, fill the first person
		if ((mask & 3<<(2*i)) == 0) {
			team[i] = cur;
			// deb(cur);
			dist = min(dist, solve(n, x, y, cur+1, mask | 2<<(2*i), team));

		} else {
			// deb("asd");
		// if 10, team half formed, fill the other person and calc dist
			dist = min(dist,
				findDist(x[team[i]], y[team[i]], x[cur], y[cur]) + 
				solve(n, x, y, cur+1, mask | 1<<(2*i), team));
		}
	}

	// dp[mask] = dist;

	return dist;
}

int main() {

	IOS

	int n;
	while (cin >> n && n > 0) {
		int x[2*n], y[2*n];
		string name;

		for (int i = 0; i < 2*n; i++)
			cin >> name >> x[i] >> y[i];

		int team[n];

		for (int j = 0; j < n; j++)
			for (int i = 0; i < (1<<2*n); i++)
				dp[j][i] = -1;

		double min_dist = solve(n, x, y, 0, 0, team);

		cout << fixed << setprecision(2) << min_dist << endl;
	}

	return 0;
}