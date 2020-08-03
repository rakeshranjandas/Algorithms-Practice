#include<iostream>
using namespace std;

long int checkIfPossible(long int a[], int n, long int maxAllowed, int m) {

	long int sumTillNow = 0, partition = 1, maxSumTillNow = 0;

	for (int i = 0; i < n; i++) {
		if (sumTillNow + a[i] <= maxAllowed)
			sumTillNow += a[i];

		else {
			sumTillNow = a[i];
			partition++;

			if (partition > m)
				return 0;
		}

		maxSumTillNow = max(maxSumTillNow, sumTillNow);
	}

	return maxSumTillNow;
}

long int minPages(long int a[], int n, int m) {

	if (m > n)
		return -1;

	long int maxm = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		maxm = max(a[i], maxm);
		sum += a[i];
	}

	if (m == n)
		return maxm;

	if (m == 1)
		return sum;

	long long int lo = 0, hi = sum, mid, maxSum, ans;
	while (lo < hi) {

		mid = (lo + hi) / 2;
		// cout << mid << " " << lo << " " << hi;
		maxSum = checkIfPossible(a, n, mid, m);
		// cout << ")" << maxSum << "("<< endl;

		if (maxSum) {
			// cout << "<";
			hi = mid;
			ans = maxSum;
		} else {
			// cout << ">";
			if (lo == mid)
				break;

			lo = mid;
		}

		// cout << endl;
	}

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		long int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int m;
		cin >> m;

		cout << minPages(a, n, m) << endl;
	}

	return 0;
}