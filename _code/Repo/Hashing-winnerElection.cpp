#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void winnerElection(string v[], int n) {

	map<string, int> m;

	int maxCount = 0;
	string winner;

	for (int i = 0; i < n; i++) {
		m[v[i]]++;

		if (m[v[i]] > maxCount) {
			maxCount = m[v[i]];
			winner = v[i];

		} else if (m[v[i]] == maxCount) {
			if (v[i].compare(winner) < 0)
				winner = v[i];
		}
	}

	cout << winner << " " << maxCount << endl;
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
		int n;
		cin >> n;

		string votes[n];
		for (int i = 0; i < n; i++)
			cin >> votes[i];

		winnerElection(votes, n);
	}

	return 0;
}