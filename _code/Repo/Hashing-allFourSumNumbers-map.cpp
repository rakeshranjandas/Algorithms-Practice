#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool uniquePairs(pair<int, int> a, pair<int, int> b) {
	return a.first != b.first && a.first != b.second && a.second != b.first && a.second != b.second;
}

void fourSum(int a[], int n, int k) {

	multimap<int, pair<pair<int, int>, bool>> pairSumMap;

	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
			pairSumMap.insert({(a[i] + a[j]), {{i, j}, true}});

	// for (auto x: pairSumMap)
	// 	cout << x.first << "{" << x.second.first.first << "," << x.second.first.second
	// 	<< "}, ";
	// cout << endl;


	set<multiset<int>>allPairsS;

	for (auto &pairSum : pairSumMap) {

		if (!pairSum.second.second)
			continue;

		int toFindSum = k - pairSum.first;
		pairSum.second.second = false;

		auto found_it = pairSumMap.equal_range(toFindSum);

		for (auto it = found_it.first; it != found_it.second; it++) {

			if (!it->second.second)
				continue;

			if (uniquePairs(pairSum.second.first, it->second.first)) {
				multiset<int> s {
					a[pairSum.second.first.first],
					a[pairSum.second.first.second],
					a[it->second.first.first],
					a[it->second.first.second]
				};
				
				allPairsS.insert(s);
			}
		}
	}

	if (allPairsS.size() > 0)
		for (auto x: allPairsS) {

			for (auto y : x) 
				cout << y << " ";

			cout << "$";
		}
	else
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

		fourSum(a, n, k);
	}

	return 0;
}