#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int josephusKill(int skip, int start_index, vector<int> v) {

	if (v.size() == 1)
		return v[0];

	int kill_index = (start_index + skip) % v.size();
	vector<int> :: iterator it = v.begin() + kill_index;

	v.erase(it);

	return josephusKill(skip, kill_index%v.size(), v);
}

int josephus(int n, int k) {
	vector<int> v;

	for (int i = 0; i < n; i++)
		v.push_back(i+1);

	return josephusKill(k-1, 0, v);
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
		int n, k;
		cin >> n >> k;

		cout << josephus(n, k) << endl;
	}

	return 0;
}