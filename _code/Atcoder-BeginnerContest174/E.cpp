#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	priority_queue<pair<double, int>> pq;
	double ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		pq.push({ip, 1});
	}

	double res, last_popped;
	bool found = false;

	while (!pq.empty()) {

		priority_queue<pair<double, int>> pqq = pq;
		while (!pqq.empty()) {
			cout << lround(pqq.top().first) << "(" << pqq.top().second << ")" << ", ";
			pqq.pop();
		}

		cout<<endl;


		auto popped_pair = pq.top();
		double popped = popped_pair.first;
		pq.pop();

		auto next_top_pair = pq.top();
		double next_big = next_top_pair.first;
		int cut_lev = 0, cuts, cnt_log;

		// cout <<"iyt";
		// deb(popped);
		// deb(next_big);

		while (popped >= next_big) {
			last_popped = popped;
			popped /= 2;
			cut_lev++;

			cuts = (1 << cut_lev - 1) * popped_pair.second;

			deb(cuts);

			cnt_log = (1 << cut_lev) * popped_pair.second;

			// deb(popped);
			// deb(cuts);
			// deb(k);
			// deb(last_popped);

			if (k-cuts < 0) {
				found = true;
				res = last_popped;
				break;
			}

			// deb(last_popped);

			k -= cuts;
		}

		if (found)
			break;

		cout << ("pushed");
		deb(lround(popped));
		deb(k);

		pq.push({popped, cnt_log});
	}

	cout << lround(res);

	return 0;
}