#include<iostream>
using namespace std;

// int findPivot(int a[], int n) {
// 	int lo = 0, hi = n-1, mid;

// 	while (lo < hi) {
// 		mid = (lo + hi) / 2;

// 	}
// }

// int findInRotatedByPivot(int a[], int n, int x) {
// 	// Find start element, break into 2 subarrays
// 	int pivot = findPivot(a, n);

// 	// Binary search on subarrays
// }

int searchInRotated(int a[], int lo, int hi, int key) {
	cout << "-->" << lo << " " << hi << endl;

	if (lo > hi)
		return -1;

	int mid = (lo + hi) / 2;

	if (a[mid] == key)
		return mid;

	if (a[lo] < a[mid]) {

		if (a[lo] <= key && key < a[mid])
			return searchInRotated(a, lo, mid-1, key);
		else
			return searchInRotated(a, mid+1, hi, key);

	} else {

		if (a[mid] < key && key <= a[hi])
			return searchInRotated(a, mid+1, hi, key);
		else
			return searchInRotated(a, lo, mid-1, key);
	}
}

int findInRotatedBySearch(int a[], int n, int x) {

	return searchInRotated(a, 0, n-1, x);
}

int findInRotated(int a[], int n, int x) {

	// return findInRotatedByPivot(a, n, x);

	return findInRotatedBySearch(a, n, x);
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

		int x;
		cin >> x;

		cout << findInRotated(a, n, x) << endl;
	}

	return 0;
}