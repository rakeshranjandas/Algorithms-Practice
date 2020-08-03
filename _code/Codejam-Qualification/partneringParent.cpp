#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		int n;
		cin >> n;

		vector<pair<int, pair<int, int>>> v;

		int start_i, end_i;

		for (int i = 0; i < n; i++) {
			cin >> start_i >> end_i;
			v.push_back({start_i, {end_i, i}});
		}

		sort(v.begin(), v.end());

		int c_end = -1, j_end = -1, start_act_i, end_act_i, act_i;
		bool cannot = false;
		char schedule[n+1];
		schedule[n] = '\0';

		for (int i = 0; i < n; i++) {

			start_act_i = v[i].first;
			end_act_i = v[i].second.first;
			act_i = v[i].second.second;

			if (start_act_i >= c_end) {
				schedule[act_i] = 'C';
				c_end = end_act_i;

			} else if (start_act_i >= j_end) {
				schedule[act_i] = 'J';
				j_end = end_act_i;

			} else {
				cannot = true;
				break;
			}
		}

		cout << "Case #" << t_i << ": " << (cannot ? "IMPOSSIBLE" : string(schedule))  << endl;
	}

	return 0;
}