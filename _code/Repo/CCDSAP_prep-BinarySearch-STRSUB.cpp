#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numPairs(vector<int> v, int l, int r, int k) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i];

	// Calculate all possible pairs
	int rng = r - l + 1;
	int count_all_pairs;

	cout << "rng " << rng << endl;

	if (2*k < rng)
		count_all_pairs = 2*k*rng - ((2*k-1)*k);
	else
		count_all_pairs = (rng*(rng+1)) / 2;

	cout << "count all pairs " << count_all_pairs << endl;

	auto start_search_it = v.begin();
	auto end_search_it = v.begin();
	advance(start_search_it, l-1);
	advance(end_search_it, r+1);

	for (auto it = start_search_it; it != end_search_it; it++) {
		auto search_it = lower_bound(start_search_it, end_search_it, (*it+k+1));
		int dist_search = distance(it, search_it);
		int end_dist = distance(search_it, end_search_it);

		cout << "Now " << *it
			<< ", Searching " << (*it+k+1) << ", found at dist " << dist_search << endl;

		
		if (search_it != end_search_it && dist_search <= 2*k) {
			cout << "dist end " << end_dist
				<< ", 2k dist " << 2*k+1 - dist_search << endl;
			cout << "excess " << min(end_dist, 2*k+1 - dist_search) << endl;
			count_all_pairs -= min(end_dist, 2*k+1 - dist_search);
		}
		
	}

	return count_all_pairs;
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
		int n, k, q;
		cin >> n >> k >> q;

		string s;
		cin >> s;

		// int a[n];
		// for (int i = 0; i < n; i++)
		// 	a[i] = s[i] - '0';

		vector <int> b;
		b.push_back(0);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += s[i]-'0';
			b.push_back(sum);
		}

		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			cout << numPairs(b, l, r, k) << endl;	
		}
	}

	return 0;
}