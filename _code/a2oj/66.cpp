#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool allSame(map<int, int> &mp, int len) {
	return mp.size() == 1 && (mp.begin())->second == len;
}

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	int v[2*n];
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
	}

	int res = -1, start = 0;

	if (allSame(mp, n))
		cout << 0;

	else {
		for (int i = 1; i <= n; i++) {
			v[start+n] = v[start+k-1];
			mp[v[start+n]]++;

			mp[v[start]]--;			
			if (mp[v[start]] == 0) {
				mp.erase(v[start]);
			}
			
			start++;

			if (allSame(mp, n)) {
				res = i;
				break;
			}
		}

		cout << res;
	}

	return 0;
}