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
		int n, pain;
		cin >> n >> pain;

		priority_queue <int> pq; 
		int ip;
		for (int i = 0; i < n; i++) {
			cin >> ip;
			pq.push(ip);
		}

		int c = 0, soldier;
		bool can_defeat = true;

		while (pain > 0) {
			if (pq.empty()) {
				can_defeat = false;
				break;
			}

			soldier = pq.top();
			pq.pop();
			pain -= soldier;
			if (soldier/2 > 0)
				pq.push(soldier/2);
			c++;

			// cout << "pain " << pain << endl;
		}

		cout << (can_defeat ? to_string(c) : "Evacuate") << endl;

	}

	return 0;
}