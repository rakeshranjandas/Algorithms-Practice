#include<iostream>
using namespace std;

int findMissingInAP(int a[], int lo, int hi, int diff) {
	// cout << lo << " - " << hi << " - " << diff << endl;

	if (lo == hi-1)
		return (a[lo] + a[hi]) / 2;

	int mid = (lo + hi) / 2;

	if ((a[mid] - a[lo]) > (mid - lo) * diff)
		return findMissingInAP(a, lo, mid, diff);

	return findMissingInAP(a, mid, hi, diff);
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

		cout << findMissingInAP(a, 0, n-1, ((a[n-1] - a[0]) / n)) << endl;
	}

	return 0;
}