#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Search an array and return index with minimum value
int searchMinimum(int a[], int lo, int hi) {
	// cout << lo << " " << hi << endl;

	if (lo == hi)
		return lo;

	int mid = (lo + hi) / 2;
    // cout << " mid=" << mid << " "<< a[mid] << endl;

    if (mid == lo && a[lo] < a[lo+1])
    	return mid;

    if (a[mid] < a[mid-1] && a[mid] < a[mid+1])
    	return mid;

	if (a[lo] < a[mid]) {
		if (a[mid] < a[hi])
			return searchMinimum(a, lo, mid-1);
		return searchMinimum(a, mid+1, hi);
	}

	if (a[mid] < a[hi])
		return searchMinimum(a, lo, mid-1);
	return searchMinimum(a, mid+1, hi);
}

int searchInRotated(int a[], int n, int k) {

	// Find minimum, so that can divide array into 2 sorted subarrays
	int minm = searchMinimum(a, 0, n-1);
	// cout << "->" << minm << " " << a[minm] << endl;

	// Search in subarray 1
	if (a[minm] <= k && k <= a[n-1])
		if (binary_search(a+minm, a+n, k))
			return distance(a, lower_bound(a+minm, a+n, k));
		else
			return -1;

	// Search in subarray 2
	if (minm > 0) {
		if (binary_search(a, a+minm, k))
			return distance(a, lower_bound(a, a+minm, k));
		else
			return -1;
	}

	return -1;
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

		int k;
		cin >> k;

		cout << searchInRotated(a, n, k)<< endl;
	}

	return 0;
}