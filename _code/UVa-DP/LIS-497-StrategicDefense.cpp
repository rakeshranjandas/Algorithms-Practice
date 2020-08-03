#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int findCeil(vector<pair<ll, int>> &dp, int val) {
	int l = 0, r = dp.size()-1, mid;

	while (l < r) {
		mid = (l+r) / 2;

		if (dp[mid].first < val)
			l = mid+1;
		else
			r = mid;
	}

	if (l > r)
		return l;
	return r;
}

void LIS(vector<ll> &v) {

	int n = v.size();
	vector<int> par(n);
	vector<pair<ll, int>> dp(n, {LONG_MAX, -1});

	int lis_len = 0, lis_i;

	for (int i = 0; i < n; i++) {
		int pos = findCeil(dp, v[i]);
		dp[pos] = {v[i], i};
		par[i] = pos == 0 ? -1 : dp[pos-1].second;

		if (lis_len < pos+1) {
			lis_len = pos+1;
			lis_i = i;
		}

		// for (auto x: dp)
		// 	cout << x.first << "(" << x.second << ") ";
		// cout << endl;
		// for (int x: par)
		// 	cout << x << " ";
		// cout << endl;
	}

	// deb(lis_i);

	// print LIS
	cout << "Max hits: " << lis_len << endl;

	string res = "";
	while (lis_i > -1) {
		res = to_string(v[lis_i]) + "\n" + res;		
		lis_i = par[lis_i];
	}

	cout << res;
}

int main() {

	IOS

	string ip;
	getline(cin, ip);

	int t = stoi(ip);

	getline(cin, ip);	

	while (t--) {

		vector<ll> v;

		while (getline(cin, ip)) {
			if (ip == "")
				break;

			v.push_back(stoll(ip));
		}

		LIS(v);
		if (t > 0)
			cout << endl;
	}

	return 0;
}