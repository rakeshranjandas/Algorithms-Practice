#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	map<char, int> mp;

	for (int i = 0; i < n; i++)
		mp[s[i]]++;

	vector<int> v;
	for (auto x: mp)
		v.push_back(x.second);

	sort(v.begin(), v.end(), greater<int>());

	ll score = 0, take;

	for (int vv: v) {

		take = min(vv, k);
		score += (ll) take * take;
		k -= take;

		// deb(vv);
		// deb(take);
		// deb(score);
		// deb(k);

		if (k <= 0)
			break;
	}

	cout << score;

	return 0;
}