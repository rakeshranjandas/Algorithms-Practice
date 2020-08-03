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
		int n, c;
		cin >> c >> n;

		priority_queue<int, vector<int>, greater<int>> pq;
		int x;

		for (int i = 0; i < n; i++) {
			cin >> x;

			if (pq.size() < c) {
				pq.push(x);

				if (pq.size() == c)
					cout << pq.top() << " ";
				else
					cout << "-1 ";

			} else {

				if (x > pq.top()) {
					pq.pop();
					pq.push(x);
				}

				cout << pq.top() << " ";
			}
		}

		cout << endl;
	}

	return 0;
}