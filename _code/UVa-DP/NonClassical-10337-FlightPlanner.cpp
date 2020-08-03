#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 100000
#define ALT 10

int dp[ALT][N];
int a[ALT][N];
int dy[3] = {-1, 0, 1};
int fuel[3] = {20, 30, 60};

bool validAlt(int alt) {
	return alt >= 0 && alt < ALT;
}

void resetDP() {
	for (int i = 0; i < ALT; i++)
		for (int j = 0; j < N; j++)
			dp[i][j] = INT_MAX;

	memset(a, 0, sizeof(a));
}

void solve() {
	int n;
	cin >> n;

	resetDP();

	int DIST = n/100;

	for (int i = ALT-1; i >= 0; i--)
		for (int j = 1; j <= DIST; j++)
			cin >> a[i][j];

	dp[0][0] = 0;

	int new_alt;

	for (int j = 0; j <= DIST; j++) {
		for (int i = 0; i < ALT; i++) {

			if (dp[i][j] == INT_MAX)
				continue;

			for (int di = 0; di < 3; di++) {
				new_alt = i + dy[di];
				if (!validAlt(new_alt))
					continue;

				dp[new_alt][j+1] = min(dp[new_alt][j+1], dp[i][j] + fuel[di] + -1*a[i][j+1]);
			}
		}
	}

	// for (int i = ALT-1; i >= 0; i--) {
	// 	for (int j = 0; j <= DIST; j++) {
	// 		cout << dp[i][j] << "(" << a[i][j] << ")" << "\t";
	// 	}
	// 	cout << endl;
	// }

	cout << dp[0][DIST] << endl;

	cout << endl;
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