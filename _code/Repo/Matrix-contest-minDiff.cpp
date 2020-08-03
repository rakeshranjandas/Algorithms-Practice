#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
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

		int ip;
		pair<int, int> a[n] = {{0, 0}};

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				cin >> ip;
				a[i].first += ip;
				a[i].second = i;
			}
		}

		int minDiff = INT_MAX;

		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < i; j++)
				minDiff = min(minDiff, a[i].first - a[j].first);
		}

		cout << minDiff << endl;
	}

	return 0;
}