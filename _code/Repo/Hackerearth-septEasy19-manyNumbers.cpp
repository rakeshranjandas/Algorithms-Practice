#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, m, l, r;
	int k;

	cin >> n >> m >> l >> r >> k;

	bool excess = false;
	vector<long long int> v;
	long long int n_mod_m = n % m;
	int v_count = 0;

	for (long long int i = l; i <= r; i++) {
		if (i != m && n%i == n_mod_m) {
			v_count++;
			if (v_count > k) {
				excess = true;
				break;
			}

			v.push_back(i);
		}
	}

	if (excess)
		cout << -1 << endl;
	else {
		cout << v.size() << endl;
		for (auto x: v)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}