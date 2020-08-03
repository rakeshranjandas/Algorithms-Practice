#include<iostream>
using namespace std;

int searchPeak(int a[], int lo, int hi) {
	if (lo == hi)
		return lo;

	if (hi - lo == 1)
		return a[hi] > a[lo] ? hi : lo;

	int mid = (lo + hi) / 2;

	if (a[mid] > a[mid-1] && a[mid] > a[mid+1])
		return mid;

	if (a[mid] <= a[mid+1])
		return searchPeak(a, mid+1, hi);

	return searchPeak(a, lo, mid-1);
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

		cout << searchPeak(a, 0, n-1) << endl;
	}

	return 0;
}