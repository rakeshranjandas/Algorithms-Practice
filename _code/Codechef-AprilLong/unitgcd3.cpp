#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

string printV(vvi v) {

	string res = to_string(v.size()) + "\n";

	for (int i = 0; i < v.size(); i++) {

		// v[i].push_back(1);

		res += to_string(v[i].size()) + " ";

		for (auto xx: v[i])
			res += to_string(xx) + " ";

		res += "\n";
	}

	return res;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

bool gcdUnique(vi &v, int n) {
	for (auto x: v) {
		if (gcd(x, n) != 1)
			return false;
	}

	return true;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vvi v;
		bool used[n+1] = {0};

		for (int i = 1; 2*i <= n; i++) {
			v.push_back(vi{1, 2*i});
			used[2*i] = true;
		}

		int vind = 0, left = n-n/2-1;

		while (left > 0) {
			for (int i = 3; i <= n; i++) {

				if (used[i])
					continue;

				if (gcdUnique(v[vind], i)) {
					v[vind].push_back(i);
					left--;
					used[i] = true;
				}

				if (left == 0)
					break;
			}

			if (left == 0)
				break;

			vind++;
		}

		cout << printV(v);

	}

	return 0;
}