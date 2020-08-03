#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

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

		int d, p, id;
		map<int, vector<int>, greater<int>> m;

		for (int i = 0; i < n; i++) {
			cin >> id >> d >> p;
			m[d].push_back(p);
		}

		// for (auto x: m) {
		// 	cout << x.first << " -(";

		// 	for (auto y: x.second) {
		// 		cout << y << ",";
		// 	}
		// 	cout << endl;
		// }


		int tm = (m.begin())->first, c = 0;

		priority_queue<int> pq;
		int max_profit = 0;
		
		while (tm > 0) {


			// deb(tm);

			if (m.find(tm) != m.end()) {
				for (auto x: m[tm])
					pq.push(x);
			}

			int max_profit_job = 0;

			if (!pq.empty()) {
				max_profit_job = pq.top();
				pq.pop();
				c++;
			}


			// deb(max_profit_job);

			max_profit += max_profit_job;

			tm--;
		}

		cout << c << " " << max_profit << endl;
	}

	return 0;
}