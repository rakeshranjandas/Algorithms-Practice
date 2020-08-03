#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define K 30

void recursiveMaxVal(int cur_ind, int cur_val, int more_plates,
		vector<stack<int>> plates, int n, int *max_val) {

	// deb(cur_ind);
	// deb(cur_val);
	// deb(more_plates);
	// cout << endl;

	if (more_plates <= 0)
		return;

	if (cur_ind >= n)
		return;

	int prev_cur_val = cur_val;

	if (!plates[cur_ind].empty()) {
		
		int popped = plates[cur_ind].top();
		plates[cur_ind].pop();
		cur_val += popped;
		*max_val = max(*max_val, cur_val);

		recursiveMaxVal(cur_ind, cur_val, more_plates-1, plates, n, max_val);
	}

	recursiveMaxVal(cur_ind+1, prev_cur_val, more_plates, plates, n, max_val);
}

int maxPlates(vector<stack<int>> &plates, int n, int p) {

	int max_val = 0;
	recursiveMaxVal(0, 0, p, plates, n, &max_val);

	return max_val;
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

	for (int t_i = 1; t_i <= t; t_i++) {
		int n, k, p;
		cin >> n >> k >> p;

		vector<stack<int>> plates;
		int a[k];

		for (int i = 0; i < n; i++) {

			for (int p = 0; p < k; p++)
				cin >> a[p];


			stack<int> s;
			plates.push_back(s);

			for (int j = k-1; j >=0; j--) {
				plates[i].push(a[j]);
			}
		}

		cout << "Case #" << t_i << ": "<< maxPlates(plates, n, p) << endl;
	}

	return 0;
}