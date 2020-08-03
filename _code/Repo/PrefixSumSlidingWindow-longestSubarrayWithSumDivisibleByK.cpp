#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printMap(unordered_map<int, int> m) {

	for (auto x: m) {
		cout << "[" << x.first << "]" << x.second << " ";
	}
	cout << endl;
}

int longestSubArr(int a[], int n, int k) {

	unordered_map<int, int> m;
	int sum = 0, max_win_len = 0, sum_mod_k;

	for (int i = 0; i < n; i++) {
		sum += a[i];
		sum_mod_k = (sum % k + k) %k;

		// If sum_mod_k is zero, then max_win_len is i+1
		if (sum_mod_k == 0) {
			max_win_len = max(max_win_len, i+1);

		} else {

			if (m.find(sum_mod_k) == m.end()) {
				m[sum_mod_k] = i;

			} else {
				max_win_len = max(max_win_len, i-m[sum_mod_k]);
			}

		}

		// cout << sum_mod_k << " - " << endl;
		// printMap(m);
	}

	return max_win_len;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;
	
	while (t--) {
	    int n, k;
	    cin >> n >> k;
	    
	    int a[n];
	    for (int i = 0; i < n; i++)
	        cin >> a[i];

	    cout << longestSubArr(a, n, k) << endl;
	}
	
	return 0;
}