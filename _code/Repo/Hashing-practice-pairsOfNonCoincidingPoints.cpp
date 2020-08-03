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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n][2];
		for (int i = 0; i < n; i++)
			cin >> a[i][0] >> a[i][1];

		unordered_map<int, unordered_map<int, int>> xm;
		unordered_map<int, unordered_map<int, int>> ym;

		for (int i = 0; i < n; i++) {
			xm[a[i][0]][a[i][1]]++;
			ym[a[i][1]][a[i][0]]++;
		}

		// cout << "X >> ";
		// for (auto x: xm) {
		// 	cout << x.first << "(";

		// 	for (auto k: x.second)
		// 		cout << "," << k.first << "<" << k.second << ">";

		// 	cout << "), ";
		// }
		// cout << endl;

		// cout << "Y >> ";
		// for (auto x: ym) {
		// 	cout << x.first << "(";

		// 	for (auto k: x.second)
		// 		cout << "," << k.first << "<" << k.second << ">";

		// 	cout << "), ";
		// }
		// cout << endl;

		int countPairs = 0;

		for (auto x: xm) {
			int totalC = 0;

			for (auto k: x.second)
				totalC += k.second;

			countPairs += (totalC * (totalC - 1)) / 2;

			for (auto k: x.second)
				countPairs -= (k.second * (k.second - 1)) / 2;
		}

		for (auto x: ym) {
			int totalC = 0;

			for (auto k: x.second)
				totalC += k.second;

			countPairs += (totalC * (totalC - 1)) / 2;

			for (auto k: x.second)
				countPairs -= (k.second * (k.second - 1)) / 2;
		}
		cout << countPairs << endl;
	}

	return 0;
}