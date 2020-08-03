#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool findInSeenMaps(vector<map<int, int>> v_m, int i, int j, int k, int l) {
	// cout << "findInSeenMaps" << endl;

	bool found = false;

	if (v_m.size()) {
		for (auto mm: v_m) {

			if (mm.find(i) != mm.end()) {
				mm[i]--;
				if (mm[i] < 0)
					continue;

			} else
				continue;

			if (mm.find(j) != mm.end()) {
				mm[j]--;
				if (mm[j] < 0)
					continue;

			} else
				continue;

			if (mm.find(k) != mm.end()) {
				mm[k]--;
				if (mm[k] < 0)
					continue;

			} else
				continue;

			if (mm.find(l) != mm.end()) {
				mm[l]--;
				if (mm[l] < 0)
					continue;

			} else
				continue;

			return true;
		}
	}

	return found;
}

void insertInSeenMaps(vector<map<int, int>> &v_m, int i, int j, int k, int l) {
	// cout << "insertInSeenMaps" << endl;
	map<int, int> m;
	m[i]++;
	m[j]++;
	m[k]++;
	m[l]++;
	v_m.push_back(m);
}

void allFourSums(int a[], int n, int sum) {

	sort(a, a+n);
	vector<map<int, int>> v_m;
	bool foundAtLeastOne = false;

	for (int i = 0; i <= n-4; i++)
		for (int j = i+1; j <= n-3; j++)
			for (int k = j+1; k <= n-2; k++)
				for (int l = k+1; l <= n-1; l++) {

					// cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					if ((a[i]+a[j]+a[k]+a[l]) == sum) {
						if (!findInSeenMaps(v_m, a[i], a[j], a[k], a[l])) {
							foundAtLeastOne = true;
							cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << " $";
							insertInSeenMaps(v_m, a[i], a[j], a[k], a[l]);
						}
					}
				}

	if (!foundAtLeastOne)
		cout << "-1";

	cout << endl;
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		allFourSums(a, n, k);
	}

	return 0;
}