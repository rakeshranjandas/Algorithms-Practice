#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void marksOf(vector<vector<long long int>> groups, int numGroups, long long int query[], int numQueries) {

	map<long long int, int> marksOffset;
	long long int prevOffsetKey = 1, prevMarksOffset = 0,
		lastGroupLength = 0, prevOffsetEnd = 1, prevGroupEnd = 0,
		key, startRange, endRange, nowOffset;

	for (int i = 0; i < numGroups; i++){

		key = prevOffsetKey + lastGroupLength;
		// startRange = *((groups + i*numGroups) + 0);
		// endRange = *((groups + i*numGroups) + 0);

		startRange = groups[i][0];
		endRange = groups[i][1];
		

		// cout << "startRange " << startRange << endl;
		// cout << "endRange " << endRange << endl;

		lastGroupLength = endRange - startRange + 1;

		// cout << "lastGroupLength " << lastGroupLength << endl;

		nowOffset = startRange - prevGroupEnd - 1 + prevMarksOffset;

		prevGroupEnd = endRange;
		prevMarksOffset = nowOffset;
		prevOffsetKey = key;

		marksOffset[key] = nowOffset;
	}

	// for (auto m: marksOffset)
	// 	cout << m.first << "(" << m.second << "), ";
	// cout << endl;


	long long int q;
	map<long long int, int> :: iterator it;
	for (int i = 0; i < numQueries; i++) {
		q = query[i];
		it = marksOffset.lower_bound(q);

		if (marksOffset.find(q) == marksOffset.end())
			it--;

		cout << (q + it->second) << " ";
	}

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
		int N, Q;
		cin >> N >> Q;

		// long long int g[N][2];
		vector<vector<long long int>> g;

		for (int i = 0; i < N; i++) {
			vector<long long int> v;
			// cin >> g[i][0] >> g[i][1];
			long long int in;
			cin >> in;
			v.push_back(in);
			cin >> in;
			v.push_back(in);

			g.push_back(v);
		}

		// for (int i = 0; i < N; i++)
		// 	cout << g[i][0] << "-" << g[i][1] << endl;

		long long int q[Q];
		for (int i = 0; i < Q; i++)
			cin >> q[i];

		marksOf(g, N, q, Q);
	}

	return 0;
}