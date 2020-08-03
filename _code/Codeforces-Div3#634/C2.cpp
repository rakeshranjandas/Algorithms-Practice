#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		unordered_map<int, int> mp;
		int ip, max_freq = 0;

		for (int i = 0; i < n; i++) {
			cin >> ip;
			mp[ip]++;
			max_freq = max(max_freq, mp[ip]);
		}

		int res, count_distinct = mp.size();

		if (count_distinct == max_freq)
			res = count_distinct - 1;
		else
			res = min(count_distinct, max_freq);

		cout << res << endl;

	}

	return 0;
}