#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int zeroSumSubArray(int a[], int n) {

	unordered_map<int, int> m;

	int sum = 0, max_win_len = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i];

		if (sum == 0)
			max_win_len = max(max_win_len, i+1);

		else {

			if (m.find(sum) != m.end())
				max_win_len = max(max_win_len, i-m[sum]);

			else
				m[sum] = i;
		}
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
	    int n;
	    cin >> n;
	    
	    int a[n];
	    for (int i = 0; i < n; i++)
	        cin >> a[i];

	    cout << zeroSumSubArray(a, n) << endl;
	}
	
	return 0;
}