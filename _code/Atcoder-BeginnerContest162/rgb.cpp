#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int jColor(int i) {
	return (i+1) % 3;
}

int kColor(int i) {
	return (i+2) % 3;
}

int color(char c) {
	return c == 'R' ? 0 : c == 'B' ? 1 : 2;
}

ll findAllJK(int cur, vector<int> v1, vector<int> v2) {
	ll c = 0;

	auto it1 = upper_bound(v1.begin(), v1.end(), cur);

	for (auto it = it1; it != v1.end(); it++) {

		auto it2 = upper_bound(v2.begin(), v2.end(), *(it));
		int c2 = distance(it2, v2.end());

		if (c2 > 0) {
			if (binary_search(v2.begin(), v2.end(), *(it) + *(it) - cur))
				c2--;

			c += c2;	
		}
	}

	return c;
}

void printV(vector<int> v) {
	for (auto x: v)
		cout << x << " ";
	cout << endl;
}

int main() {

	IOS

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<vector<int>> v;
	v.resize(3);

	int red = 0, blue = 1, green = 2;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'R')
			v[red].push_back(i);

		else if (s[i] == 'G')
			v[green].push_back(i);

		else if (s[i] == 'B')
			v[blue].push_back(i);
	}

	int color_i, color_j, color_k;
	ll c = 0;

	for (int i = 0; i < n-2; i++) {
		color_i = color(s[i]);
		color_j = jColor(color_i);
		color_k = kColor(color_i);

		c += findAllJK(i, v[color_j], v[color_k]);
		c += findAllJK(i, v[color_k], v[color_j]);
	}

	cout << c << endl;

	return 0;
}