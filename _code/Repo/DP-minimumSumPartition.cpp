#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int minSumPartition(int a[], int n) {

	set<int> s;
	s.insert(0);

	int total = 0;
	vector<int> now_v;

	for (int i = 0; i < n; i++) {
		total += a[i];

		now_v.assign(s.begin(), s.end());
		int now_v_size = s.size();

		for (int j = 0; j < now_v_size; j++) {
			s.insert(now_v[j] + a[i]);
		}

		now_v.clear();
	}

	now_v.assign(s.begin(), s.end());

	// for (auto &x: s)
	// 	cout << x << " ";
	// cout << endl;


	// deb(total);


	// for (int i = 0; i < now_v.size(); i++)
	// 	cout << now_v[i] << " ";

	// cout << endl;

	int first, second, res = INT_MAX;

	for (int i = 1; i < now_v.size(); i++) {
		first = now_v[i];
		second = total - first;
		res = min(res, abs(first - second));

		// cout << first << " " << second << " " << res << endl;
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << minSumPartition(a, n) << endl;
	}

	return 0;
}