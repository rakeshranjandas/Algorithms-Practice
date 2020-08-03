#include<iostream>
using namespace std;
typedef long long int ll;

ll findOneOccurence(ll a[], int lo, int hi, int n) {


	if (lo == hi)
		return a[lo];

	int mid = (lo+hi) / 2;

	// cout << lo << " " << hi << " " << mid << endl;

	// Check if mid is the answer
	if ((mid-1 < 0 || a[mid] != a[mid-1]) && (mid+1 >= n || a[mid] != a[mid+1]))
		return a[mid];

	if (mid % 2 == 1) {
		if (mid-1 >= 0 && a[mid-1] == a[mid])
			return findOneOccurence(a, mid+1, hi, n);

		else
			return findOneOccurence(a, lo, mid, n);

	} else {
		if (mid-1 >= 0 && a[mid-1] == a[mid])
			return findOneOccurence(a, lo, mid, n);

		else
			return findOneOccurence(a, mid+1, hi, n);
	}
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

		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << findOneOccurence(a, 0, n-1, n) << endl;
	}

	return 0;
}