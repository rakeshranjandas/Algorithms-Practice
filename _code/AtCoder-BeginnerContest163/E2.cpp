#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 2005

typedef long long int ll;
typedef vector<pair<int, int>> vpi;
typedef unordered_map<int, unordered_map<int, int>> ump;

ll dp[N][N];

bool present(int l, int r) {
	return dp[l][r] != -1;
}

ll maxHappiness(vpi &v, int n, int cur, int l, int r) {

	if (l > r)
		return 0;

	if (present(l, r))
		return dp[l][r];

	ll put_in_left = (ll)v[cur].first * abs(v[cur].second-l) + maxHappiness(v, n, cur+1, l+1, r);
	ll put_in_right = (ll)v[cur].first * abs(v[cur].second-r) + maxHappiness(v, n, cur+1, l, r-1);

	dp[l][r] = max(dp[l][r], max(put_in_left, put_in_right));

	return dp[l][r];
}

int main() {

	int n;
	cin >> n;
	
	vpi v;
	int ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		v.push_back({ip, i});
	}

	sort(v.begin(), v.end(), greater<pair<int,int>>());
	memset(dp, -1, sizeof(dp));

	cout << maxHappiness(v, n, 0, 0, n-1);

	return 0;
}