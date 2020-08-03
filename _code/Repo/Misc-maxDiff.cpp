#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int findMaxDiff(int a[], int n) {

	int ls[n] = {0}, rs[n] = {0};

	for (int i = 0; i < n; i++) {

		for (int j = i-1; j >= 0; j--) {
			if (a[j] < a[i]) {
				ls[i] = a[j];
				break;
			}
		}

		for (int j = i+1; j < n; j++) {
			if (a[j] < a[i]) {
				rs[i] = a[j];
				break;
			}
		}
	}

	// for (int i = 0; i < n; i++)
	// 	cout << ls[i];
	// cout << endl;

	// for (int i = 0; i < n; i++)
	// 	cout << rs[i];
	// cout << endl;

	int max_diff = 0;
	for (int i = 0; i < n; i++)
		max_diff = max(max_diff, abs(ls[i] - rs[i]));
	
	return max_diff;
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
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << findMaxDiff(a, n) << endl;
	}

	return 0;
}