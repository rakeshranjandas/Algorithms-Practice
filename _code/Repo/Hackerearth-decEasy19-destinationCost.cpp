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

	int n;
	cin >> n;
	int car[n], bus[n];

	for (int i = 0; i < n; i++)
		cin >> car[i];

	for (int i = 0; i < n; i++)
		cin >> bus[i];

	vector<pair<int, int>> diff;
	for (int i = 0; i < n; i++)
		diff.push_back(make_pair(car[i] - bus[i], i));


	sort(diff.begin(), diff.end());

	// for (auto x: diff)
	// 	cout << x.first << "(" << x.second << ") ";
	// cout << endl;

	long long int cost = 0;

	int i = 0;
	for (; i < n/2; i++) {
		// cout << "car " << car[diff[i].second] << endl;
		cost += car[diff[i].second];
	}

	if (n%2) {
		if (diff[i].first < 0)
			cost += car[diff[i].second];
		else
			cost += bus[diff[i].second];
		
		i++;
	}

	for (; i < n; i++) {
		// cout << "bus " << bus[diff[i].second] << endl;
		cost += bus[diff[i].second];
	}

	cout << cost << endl;

	

	return 0;
}