#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef vector<pair<ll, int>> vpi;

void printVPI(vpi v) {
	for (auto x: v) {
		cout << x.first << "[" << x.second << "] ";
	}
	cout << endl;
}

int findPosInc(vpi &inc, int e, ll val) {

	int l = 0, r = e, mid;

	while (l < r) {
		mid = (l+r) / 2;

		if (inc[mid].first < val)
			l = mid+1;

		else
			r = mid;
	}

	// deb(l); deb(r);

	if (l > r)
		return l;
	return r;
}

void LIS(vpi &v) {

	int n = v.size();
	vpi inc;
	inc.push_back({LONG_MAX, -1});

	int par[n], e = 0;
	int pos = 0, max_lis_len = 1, max_lis_len_i;

	// printVPI(v);

	for (int i = 0; i < n; i++) {
		ll val =  v[i].first;
		int new_pos = findPosInc(inc, e, val);

		// deb(val);
		// deb(new_pos);

		inc[new_pos] = {val, v[i].second};

		if (e < new_pos+1 && new_pos+1 < n) {
			e = new_pos+1;
			inc.push_back({LONG_MAX, -1});
		}

		par[i] = new_pos == 0 ? -1: inc[new_pos-1].second;

		if (max_lis_len <= new_pos+1) {
			max_lis_len = new_pos+1;
			max_lis_len_i = i;
		}

		// printVPI(inc);
	}

	string res = "";
	while (max_lis_len_i > -1) {
		res = to_string(v[max_lis_len_i].first) + "\n" + res;
		max_lis_len_i = par[max_lis_len_i];
	}
	cout << max_lis_len << "\n-\n" << res;
}

int main() {

	IOS

	vpi v;
	ll ip;
	int i = 0;

	while (cin >> ip)
		v.push_back({ip, i++});

	LIS(v);

	return 0;
}