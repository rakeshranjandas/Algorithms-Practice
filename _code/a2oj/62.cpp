#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 100001

int main() {

	IOS

	int n;
	cin >> n;

	vector<vector<int>> v(N);
	int ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		v[ip].push_back(i);
	}

	vector<pair<int, int>> res;

	for (int i = 1; i < N; i++) {
		if (v[i].size() == 0)
			continue;

		if (v[i].size() == 1) {
			res.push_back({i, 0});
			continue;
		}

		bool in_ap = true;
		int diff = v[i][1] - v[i][0];

		for (int j = 2; j < v[i].size(); j++)
			if (v[i][j] - v[i][j-1] != diff) {
				in_ap = false;
				break;
			}

		if (in_ap)
			res.push_back({i, diff});
	}

	cout << res.size() << endl;
	for (auto p: res)
		cout << p.first << " " << p.second << endl;

	return 0;
}