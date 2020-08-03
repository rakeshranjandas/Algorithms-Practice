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
		
		priority_queue<int, vector<int>> pq;
		int x;

		for (int i = 0; i < n; i++) {
			cin >> x;
			pq.push(x);
		}

		for (auto x: pq)
			cout << x << " ";

		cout << endl;
			
	}

	return 0;
}