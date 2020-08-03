#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int findCeil(vector<int> &inc, int val) {
	int l = 0, r = inc.size()-1, mid;

	while (l < r) {
		mid = l + (r-l) / 2;

		if (inc[mid] >=  val)
			r = mid;
		else
			l = mid+1;
	}

	return r;
}

void LIS(vector<int> &v, vector<int> &dp) {

	int n = v.size();
	vector<int> inc(n, INT_MAX);
	int new_pos;

	for (int i = 0; i < n; i++) {
		new_pos = findCeil(inc, v[i]);

		inc[new_pos] = v[i];
		dp[i] = new_pos+1;
	}
}

void WAVIO(vector<int> &v) {

	int n = v.size();
	vector<int> dp(n, 1), dp_rev(n, 1);

	LIS(v, dp);

	reverse(v.begin(), v.end());
	LIS(v, dp_rev);

	int wavio_len = 1;
	for (int i = 0; i < n; i++) {
		if (dp[i] == 1 || dp_rev[n-1-i] == 1)
			continue;
		wavio_len = max(wavio_len, min(dp[i], dp_rev[n-1-i]) * 2 - 1);
	}

	cout << wavio_len << endl;
}

int main() {

	IOS

	int n;
	while (cin >> n) {
		vector<int> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		WAVIO(v);
	}

	return 0;
}