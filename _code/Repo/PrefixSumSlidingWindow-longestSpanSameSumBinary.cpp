#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestSpan(int a[], int b[], int n) {

	int sum_a[n+1], sum_b[n+1];
	sum_a[0] = 0;
	sum_b[0] = 0;

	for (int i = 1; i < n+1; i++) {
		sum_a[i] = sum_a[i-1] + a[i-1];
		sum_b[i] = sum_b[i-1] + b[i-1];
	}

	int max_win_len = 0;

	for (int j = n; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (sum_a[j]-sum_a[i] == sum_b[j]-sum_b[i])
				max_win_len = max(max_win_len, j-i);
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
	    
	    int a[n], b[n];
	    for (int i = 0; i < n; i++)
	        cin >> a[i];

	    for (int i = 0; i < n; i++)
	        cin >> b[i];

	    cout << longestSpan(a, b, n) << endl;
	}
	
	return 0;
}