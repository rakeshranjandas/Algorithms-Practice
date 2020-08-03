#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 5001

int main() {

	IOS

	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int n;
	cin >> n;

	vector<vector<int>> v(N);
	int x;

	for (int i = 1; i <= 2*n; i++) {
		cin >> x;
		v[x].push_back(i);
	}


	string res = "";

	for (auto vv: v) {
		if (vv.size() == 0)
			continue;

		if (vv.size() % 2 != 0) {
			res = "-1";
			break;
		}
	}

	if (res == "") {
		for (auto vv: v) {
			if (vv.size() == 0)
				continue;

			for (int i = 0; i < vv.size(); i+=2)
				cout << vv[i] << " " << vv[i+1] << endl;
		}
	}

	cout << res;

	return 0;
}